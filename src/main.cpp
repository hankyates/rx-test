#include "rxcpp/rx.hpp"
#include "daisy_seed.h"

daisy::DaisySeed hw;

namespace Rx {
  using namespace rxcpp;
  using namespace rxcpp::sources;
  using namespace rxcpp::operators;
  using namespace rxcpp::util;
}
using namespace Rx;
using namespace std;

auto audioSubj = Rx::subjects::subject<float>();
auto audio$ = audioSubj.get_observable();
auto audioObserver = audioSubj.get_subscriber();

void AudioCallback(float **in, float **out, size_t size)
{
  audioObserver.on_next(in[0][0]); // just for testing
  for (size_t i = 0; i < size; i++)
  {
    out[0][i] = in[0][i];
    out[1][i] = in[1][i];
  }
}

int main()
{
  hw.Configure();
  hw.Init(AudioCallback);
  hw.StartAudio();

  audio$ |
    subscribe<float>(println(cout));
}
