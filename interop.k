Import Function
Import Gen

Main() {
	freq = Control:Param("freq" 440)
	w = Gen:Phasor(freq)
	wave = Function:Table-Period-Smooth[-1 1 -0.5 0.5 -0.1 0.1]

	Main = wave(w)
}