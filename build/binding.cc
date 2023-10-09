#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <iostream>
#include <fst/fstlib.h>
using namespace std;
#include <include/PhonetisaurusScript.h>
#include <include/util.h>
#include <iomanip>

using namespace fst;

class PhonemizerWrapper
{
public:
  PhonemizerWrapper(const string &model_file, const string &deli)
  {
    this->decoder = new PhonetisaurusScript(model_file, deli);
  }

  ~PhonemizerWrapper()
  {
    if (this->decoder)
    {
      delete this->decoder;
    }
  }

  emscripten::val Phoneticize(const string &word, int nbest = 1,
                              int beam = 500, float threshold = 10,
                              bool write_fsts = false,
                              bool accumulate = false,
                              double pmass = 0.0)
  {
    vector<PathData> results = this->decoder->Phoneticize(
        word, nbest,
        beam,
        threshold,
        write_fsts,
        accumulate,
        pmass);

    std::vector<emscripten::val> data;
    for (int i = 0; i < results.size(); i++)
    {
      std::vector<std::string> items;
      for (int j = 0; j < results[i].Uniques.size(); j++)
      {
        std::string result = this->decoder->osyms_->Find(results[i].Uniques[j]);
        items.push_back(result);
      }
      data.push_back(emscripten::val::array(items));
    }

    return emscripten::val::array(data);
  }

private:
  PhonetisaurusScript *decoder;
};

EMSCRIPTEN_BINDINGS(my_module)
{
  emscripten::class_<PhonemizerWrapper>("Phonemizer")
      .constructor<std::string, std::string>()
      .function("phoneticize", &PhonemizerWrapper::Phoneticize);
      
}