#include "interop.h"

#include <vector>

int main() {
	float rate = 44100;
	auto wavetable = new Wavetable(&rate);
	
	float freq = 440;
	wavetable->SetFreq(&freq);
	wavetable->TickFreq(nullptr);

	std::vector<float> output(128);
	wavetable->TickAudio(output.data(), output.size());
}