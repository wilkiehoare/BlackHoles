// preprocessor directives
#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
// main function
int main() {
	class BlackHole {
		public:
			// constants
			float G = 6.67 * pow(10, -11);
			float c = 3.00 * pow(10, 8);
			float h = 6.63 * pow(10, -34);
			float pi = acos(-1);
			float hbar = h/(2 * pi);
			float k = 1.38 * pow(10, -23);
			float sigma = 5.67 * pow(10, -8);
			float UniverseTemp = 2.73;
			// defining variables used within multiple methods
			double radius;
			double temperature;
			// methods
			double Radius(double SolarMass) {
				radius = (2 * G * SolarMass)/pow(c, 2);
				return radius;
				}
			double Density(double SolarMass) {
				double density = (3 * pow(c, 6))/(32 * pi * pow(G, 3) * pow(SolarMass, 2));
				return density;
				}
			double Temperature(double SolarMass) {
				temperature = (hbar * pow(c, 3))/(8 * pi * G * k * SolarMass);
				return temperature;
				}
			double Radiation(double SolarMass) {
				double radiation = 4 * pi * pow(radius, 2) * sigma * pow(temperature, 4);
				return radiation;
				}
			double ThermalEquilibrium(double SolarMass) {
				double TE1 = (24 * pow(pi, 3) * pow(k, 4) * pow(G, 3) * pow(SolarMass, 4))/(sigma * pow(hbar, 4) * pow(c, 9));
				double TE2 = sqrt(TE1);
				return TE2;
				}
	};
	for(int n = 1; n < 513; n++) {
		double SolarMass = n * 2 * pow(10, 30);
		BlackHole blackhole;
		// all values
		ofstream file1;
		file1.open("AllValues.txt", fstream::app);
		file1 << "Solar Mass " << n << ":" << endl;
		file1 << "Radius = " << blackhole.Radius(SolarMass) << " m" << endl;
		file1 << "Density = " << blackhole.Density(SolarMass) << " kg m^-3" << endl;
		file1 << "Temperature = " << blackhole.Temperature(SolarMass) << " K" << endl;
		file1 << "Radiation = " << blackhole.Radiation(SolarMass) << " W m^-2" << endl;
		file1 << "Time to reach Thermal Equilibrium = " << blackhole.ThermalEquilibrium(SolarMass) << " s = " << blackhole.ThermalEquilibrium(SolarMass)/(3.1536 * pow(10, 7)) << " years" << endl << endl;
		file1.close();
		// radius vs solar mass
		ofstream file2;
		file2.open("RadiusSM.csv", fstream::app);
		file2 << n << " , " << blackhole.Radius(SolarMass) << endl;
		file2.close();
		// temperature vs solar mass
		ofstream file3;
		file3.open("TempSM.csv", fstream::app);
		file3 << n << " , " << blackhole.Temperature(SolarMass) << endl;
		file3.close();
		// radiation vs solar mass
		ofstream file4;
		file4.open("RadiationSM.csv", fstream::app);
		file4 << n << " , " << blackhole.Radiation(SolarMass) << endl;
		file4.close();
		// equilibrium vs solar mass
		ofstream file5;
		file5.open("EquiSM.csv", fstream::app);
		file5 << n << " , " << blackhole.ThermalEquilibrium(SolarMass) << endl;
		file5.close();
		// density vs solar mass
		ofstream file6;
		file6.open("DensitySM.csv", fstream::app);
		file6 << n << " , " << blackhole.Density(SolarMass) << endl;
		file6.close();
		// radius vs density
		ofstream file7;
		file7.open("RadiusDensity.csv", fstream::app);
		file7 << blackhole.Radius(SolarMass) << " , " << blackhole.Density(SolarMass) << endl;
		file7.close();
		// radius vs temperature
		ofstream file8;
		file8.open("RadiusTemp.csv", fstream::app);
		file8 << blackhole.Radius(SolarMass) << " , " << blackhole.Temperature(SolarMass) << endl;
		file8.close();
		// radius vs radiation
		ofstream file9;
		file9.open("RadiusRadiation.csv", fstream::app);
		file9 << blackhole.Radius(SolarMass) << " , " << blackhole.Radiation(SolarMass) << endl;
		file9.close();
		// radius vs equilibrium
		ofstream file10;
		file10.open("RadiusEqui.csv", fstream::app);
		file10 << blackhole.Radius(SolarMass) << " , " << blackhole.ThermalEquilibrium(SolarMass) << endl;
		file10.close();
		// temperature vs density
		ofstream file11;
		file11.open("TempDensity.csv", fstream::app);
		file11 << blackhole.Temperature(SolarMass) << " , " << blackhole.Density(SolarMass) << endl;
		file11.close();
		// temperature vs radiation
		ofstream file12;
		file12.open("TempRadiation.csv", fstream::app);
		file12 << blackhole.Temperature(SolarMass) << " , " << blackhole.Radiation(SolarMass) << endl;
		file12.close();
		// temperature vs equilibrium
		ofstream file13;
		file13.open("TempEqui.csv", fstream::app);
		file13 << blackhole.Temperature(SolarMass) << " , " << blackhole.ThermalEquilibrium(SolarMass) << endl;
		file13.close();
		// radiation vs equilibrium
		ofstream file14;
		file14.open("RadiationEqui.csv", fstream::app);
		file14 << blackhole.Radiation(SolarMass) << " , " << blackhole.ThermalEquilibrium(SolarMass) << endl;
		file14.close();
		// radiation vs density
		ofstream file15;
		file15.open("RadiationDensity.csv", fstream::app);
		file15 << blackhole.Radiation(SolarMass) << " , " << blackhole.Density(SolarMass) << endl;
		file15.close();
		// equilibrium vs density
		ofstream file16;
		file16.open("EquiDensity.csv", fstream::app);
		file16 << blackhole.ThermalEquilibrium(SolarMass) << " , " << blackhole.Density(SolarMass) << endl;
		file16.close();
		cout << n << endl;
	}
	return 0;
}
