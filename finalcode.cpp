#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>
using namespace std;
float e1 = 8.85;
class resistance
{
private:
    float i, n, resistance, sum = 0;
    float parallel;

public:
    // we have created a memeber function
    void series_resistance()
    {
        cout << endl;
        cout << endl;

        cout << "You are in Series resistance " << endl;
        cout << "How many resistance you want to enter ? ";
        cin >> n;
        for (i = 1; i <= n; i++) // using for loop we are taking the n number of entries
        {

            cout << "the value of " << (i) << " resistance is ";
            cin >> resistance;
            sum = sum + resistance;
        }
        cout << "The equivalient resistance of " << n << " resistance is " << sum << " ohm";
    }
    void parallel_resistance()
    {
        cout << endl;
        cout << endl;

        cout << "you are in parallel resistance " << endl;
        cout << "How many resistance you want to enter ? ";
        cin >> n;
        for (i = 1; i <= n; i++) // using for loop we are taking the n number of entries
        {

            cout << "the value of " << (i) << " resistance is ";
            cin >> resistance;
            sum = sum + (1 / resistance);
        }
        //   1/r = 1/r1 + 1/r2
        // float parallel;
        parallel = (1 / sum);
        cout << "The equivalient resistance of " << n << " resistance is " << parallel << " ohm" << endl;
    }
};

class capacitor // creat an another class for capacitor
{
    // we are in private
private:
    float n, capacitor, sum = 0;
    float series;
    int i;
    float e2 = e1 * pow(10, -12); // e2 = 8.85 * 10 ^(-12)
    float A, d;
    float C, K;
    float r1, r2, pi, l; // pi is only inisilize over here
    float p, s;
    float Q, F;
    // we are in public now
public:
    // Create a member function for series capacitor
    // The logic in series capacitor is same as of parallel resistance connection
    void series_capacitor()
    {
        cout << endl;
        cout << endl;

        cout << "you are in series capacitor " << endl;
        cout << "How many capacitor you want to enter ? ";
        cin >> n;
        for (i = 1; i <= n; i++) // using for loop we are taking the n number of entries
        {
            cout << "the value of " << (i) << " capacitor is ";
            cin >> capacitor;
            sum = sum + (1 / capacitor); // C
        }
        series = (1 / sum); // 1/C = 1/c1 + 1/C2
        cout << "The equivalient capacitance of " << n << " capacitor is in series connection is " << series << " Farad" << endl;
    }

    // Create a member function for parallel capacitor
    // The logic in parallel capacitor is same as of series resistance connection
    void parallel_capacitor()
    {
        cout << endl;
        cout << endl;

        cout << "you are in parallel capacitor " << endl;
        cout << "How many capacitor you want to enter ? ";
        cin >> n;
        for (i = 1; i <= n; i++) // using for loop we are taking the n number of entries
        {
            cout << "the value of " << (i) << " capacitor is ";
            cin >> capacitor;
            sum = sum + capacitor; // C = C1 + C2
        }
        cout << "The equivalient capacitance of " << n << " capacitor is in parallel connection is " << sum << " Farad";
    }

    // Creating logic for parallel plate capacitor taking air as medium
    // when air is di-electric medium then value of K is 1
    void Parallel_plate_capacity()
    {
        cout << endl;
        cout << endl;
        cout << setprecision(3); // Will go only three digit after point
        cout << "A is Area of plate " << endl;
        cout << "d is Distance between plates " << endl;
        cout << "Enter the value of A : ";
        cin >> A;
        cout << "Enter the value of d : ";
        cin >> d;
        cout << "The capacitance of capacitor is given by c=(A*e0)/d " << endl;
        C = (A * e2) / d; // e2 = e0
        cout << "The value of capacitance is " << C;
    }

    // Creating logic for parallel plate capacitor taking K as medium
    void Parallel_plate_K_As_medium()
    {
        cout << endl;
        cout << endl;
        cout
            << setprecision(3);
        cout << "A is Area of plate " << endl;
        cout << "d is Distance between plates " << endl;
        cout << "K is medium between plates " << endl;
        cout << "Enter the value of A : ";
        cin >> A;
        cout << "Enter the value of d : ";
        cin >> d;
        cout << "Enter the value of K : ";
        cin >> K;
        cout << "The capacitance of capacitor is given by C=(A*e0k)/d " << endl;
        C = (A * e2 * K) / d;
        cout << "The value of capacitance is " << C;
    }

    // Creating logic for Spherical capacitor
    void spherical_capacitor()
    {
        cout << endl;
        cout << endl;
        cout << setprecision(3);
        cout << "r1 is radius of inner sphere " << endl;
        cout << "r2 is radius of outer sphere " << endl;
        cout << "C is cpacitance of that sphere body " << endl;
        cout << "Enter value of r1 ";
        cin >> r1;
        cout << "Enter value of r2 ";
        cin >> r2;
        pi = 3.142;
        C = (4 * pi * e2 * r1 * r2) / (r2 - r1); // formula of Capacity of spherical capacitor
        cout << "The capacitance of speherical body is " << C;
    }

    // creating logic for Cylinderical Capacitance
    void cylinderical_capacitance()
    {
        cout << endl;
        cout << endl;
        cout << setprecision(3);
        cout << "r1 is radius of inner cylinder " << endl;
        cout << "r2 is radius of outer cylinder " << endl;
        cout << "l is length of cylinder " << endl;
        cout << "C is cpacitance of that cylinderical body " << endl;
        cout << "Enter the value of r1 ";
        cin >> r1;
        cout << "Enter the value of r2 ";
        cin >> r2;
        cout << "Enter the calue of l ";
        cin >> l;
        pi = 3.142;
        p = (2 * pi * e2 * l); // N part
        s = (r2 / r1);         // half-D  part
        float Z;
        Z = log10(s); // log (r2/r1)
        C = (p) / Z;  // C= (2 * pi * e0 * l) / log(r2/r1)
        cout << "The cpacitance of the cylinderical body is " << C;
    }

    // creating logic for force between parallel plate capacitor
    void force()
    {
        cout << endl;
        cout << endl;

        cout << " A is area of parallel plate capacitor " << endl;
        cout << " Q charge on capacitior " << endl;
        cout << " F is attractive force between them " << endl;
        cout << "Finding the force between the parallel plate capacitors." << endl;

        cout << "Enter the value of Q: ";
        cin >> Q;

        cout << "Enter the value of A: ";
        cin >> A;

        F = (Q * Q) / (2 * A * e2); // F = (Q^2)/(2*A*e0)

        cout << "Force between parrallel plate capacitor is " << F << endl;
    }
};

/*
There are nearly 13^13 switch cases in this code which is time consuming and which makes the code large.
So only 5 switch cases are demonstrated in this code.
                            sequence to be used --> 1101000000110
                                                    0110000100100
                                                    0100000000110
                                                    0100000000110
                                                    0000100000001

*/

int switch_case(string ckt)
{
    int SCase;

    // I = current
    // V = Voltage
    // P = Power
    // R = Resistance
    // Z = Impedence
    // Xc = Capacitive reactance
    // Vc = Volatge across capacitor
    // Vr = Voltage across resistance
    // Pf = Power factor
    // W = Angular frequency
    // C = Capacitance
    // phi = Angle

    // The sequence is as follows
    //  I V P R Z Xc Vc Vr Pf W f c phi

    // 1 Stand for the Yes and 0 Stand for the no

    if (ckt == "1101000000110")
    {
        SCase = 1;
    }
    else if (ckt == "0110000100100")
    {
        SCase = 2;
    }
    else if (ckt == "0100000000110")
    {
        SCase = 3;
    }
    else if (ckt == "0100000000110")
    {
        SCase = 4;
    }
    else if (ckt == "0000100000001")
    {
        SCase = 5;
    }
    else
    {
        SCase = 0;
    }

    switch (SCase)
    {

    // Case 1
    case (1):
    {
        float I, V, R, f, c;
        cout << endl;
        cout << endl;
        cout << "Enter the value of I: ";
        cin >> I;

        cout << "Enter the value of V: ";
        cin >> V;

        cout << "Enter the value of R: ";
        cin >> R;

        cout << "Enter the value of f: ";
        cin >> f;

        cout << "Enter the value of c: ";
        cin >> c;

        // Calculating all Possible Results

        float P = pow(I, 2) * R;
        float w = 2 * 3.142 * f;
        float Xc = 1 / (w * c);
        float z = pow(R, 2) * pow(Xc, 2);
        float Z = pow(z, 0.5);
        float Vmax = pow(2, 0.5) * V;
        float Imax = pow(2, 0.5) * I;
        float pf = R / Z;
        float phi = acos(pf);
        float Vc = I * Xc;

        // Printing all Possible Results

        cout << "\nThe total possible results are:\n";
        cout << "Power                      = " << P << " W" << endl;
        cout << "Angular velocity           = " << w << " rad/sec" << endl;
        cout << "Capacitive Reactance(Xc)   = " << Xc << " ohm" << endl;
        cout << "Impedance(Z)               = " << Z << " ohm" << endl;
        cout << "Maximum Voltage(Vmax)      = " << Vmax << " V" << endl;
        cout << "Maximum Current            = " << Imax << " A" << endl;
        cout << "Power Factor               = " << pf << endl;
        cout << "phi                        = " << phi << " rad" << endl;
        cout << "Voltage across Capacitance = " << Vc << " V" << endl;

        break;
    }

    // Case 2
    case (2):
    {
        float P, Vr, V, f;
        cout << endl;
        cout << endl;
        cout << "Enter the value of V : ";
        cin >> V;

        cout << "Enter the value of P : ";
        cin >> P;

        cout << "Enter the value of Vr: ";
        cin >> Vr;

        cout << "Enter the value of f : ";
        cin >> f;

        // Calculating all Possible Results

        float I = P / Vr;
        float vc = pow(V, 2) - pow(Vr, 2);
        float Vc = pow(vc, 0.5);
        float Xc = Vc / I;
        float w = 2 * 3.142;
        float C = 1 / (w * Xc);
        float pf = Vr / V;
        float phi = acos(pf);

        // Printing all Possible Results

        cout << "\nThe total possible results are:\n";
        cout << "Irms                         = " << I << " A" << endl;
        cout << "Voltage across Capacitor(Vc) = " << Vc << " V" << endl;
        cout << "Capacative Reactance(Xc)     = " << Xc << " ohm" << endl;
        cout << "Angular frequency(w)         = " << w << " rad" << endl;
        cout << "Capacitance(C)               = " << C << " uf" << endl;
        cout << "Power Factor(pf)             = " << pf << endl;
        cout << "phi                          = " << phi << " rad" << endl;

        break;
    }

    // Case 3
    case (3):
    {
        float C, V, f;
        cout << endl;
        cout << endl;
        cout << "Enter the value of C: ";
        cin >> C;

        cout << "Enter the value of V: ";
        cin >> V;

        cout << "Enter the value of f: ";
        cin >> f;

        // Calculating all Possible Results

        float w = 2 * 3.14 * f;
        float Xc = 1 / (w * C);
        float Imax = (V * pow(2, 0.5)) / Xc;
        float Irms = Imax / pow(2, 0.5);

        // Printing all Possible Results

        cout << "\nThe total possible results are:\n";
        cout << "Angular frequency(w)     = " << w << " rad" << endl;
        cout << "Capacitive Reactance(Xc) = " << Xc << " ohm" << endl;
        cout << "Maximum Current(Imax)    = " << Imax << " A" << endl;
        cout << "RMS Current(Irms)        = " << Irms << " A" << endl;
        cout << "phi                      = pi/2"
             << " rad" << endl;

        break;
    }

    // Case 4
    case (4):
    {
        float pf, Z, I, C, f;
        cout << endl;
        cout << endl;
        cout << "Enter the value of pf: ";
        cin >> pf;

        cout << "Enter the value of Z: ";
        cin >> Z;

        cout << "Enter the value of C: ";
        cin >> C;

        cout << "Enter the value of f: ";
        cin >> f;

        // Calculating all Possible Results
        float R = Z * pf;
        float P = pow(I, 2) * R;
        float w = 2 * 2.142 * C;
        float Xc = 1 / (w * C);
        float phi = acos(pf);

        // Printing all Possible Results
        cout << "\nThe total possible results are:\n";
        cout << "Ohmic Resistance(R)      = " << R << " ohm" << endl;
        cout << "Total Power(P)           = " << P << "  W" << endl;
        cout << "Angular Frequency(w)     = " << w << " rad/sec" << endl;
        cout << "Capacitive Reactance(Xc) = " << Xc << " ohm" << endl;
        cout << "phi                      = " << phi << " rad" << endl;

        break;
    }

    // Case 5
    case (5):
    {
        cout << "\nData Insufficient.";
    }
    default:
    {
        cout << "\nEnter proper data.";
    }
    }
    return 0;
}

// Function to concatenate
// two integers into one
string concat(string I, string V, string P, string R, string Z, string Xc, string Vc, string Vr, string pf, string w, string f, string C, string phi)
{
    // Concatenate all the strings
    string s = I + V + P + R + Z + Xc + Vc + Vr + pf + w + f + C + phi;

    // Convert the concatenated string to integer

    // return the formed integer

    return s;
}

string ask_input()
{
    string I, V, P, R, Z, Xc, Vc, Vr, pf, w, f, C, phi;

    cout << endl;
    cout << "1 is for given and 0 is for not given " << endl;
    cout << endl;

    cout << ("Is the value of I given: ");
    cin >> I;

    cout << ("Is the value of V given: ");
    cin >> V;

    cout << ("Is the value of P given: ");
    cin >> P;

    cout << ("Is the value of R given: ");
    cin >> R;

    cout << ("Is the value of Z given: ");
    cin >> Z;

    cout << ("Is the value of Xc given: ");
    cin >> Xc;

    cout << ("Is the value of Vc given: ");
    cin >> Vc;

    cout << ("Is the value of Vr given: ");
    cin >> Vr;

    cout << ("Is the value of pf given: ");
    cin >> pf;

    cout << ("Is the value of w given: ");
    cin >> w;

    cout << ("Is the value of f given: ");
    cin >> f;

    cout << ("Is the value of C given: ");
    cin >> C;

    cout << ("Is the value of phi given: ");
    cin >> phi;

    string seq = concat(I, V, P, R, Z, Xc, Vc, Vr, pf, w, f, C, phi);

    return seq;

    // return seq;
}

class LRC
{
private:
    float Xl, Xc, Vmax, Imax, R, f, L, pf, Z, C, Vrms, Irms, Womega, Power;

public:
    void RLC_inductive_circuit()
    {
        cout << endl;
        cout << endl;
        cout << "as Xl is grater than Xc therefore RLC circuit behave's like an inductive circuit" << endl;

        // Xl = inductive resistance
        // Xc = capacitive resistance
        // Vrms = root mean square voltage
        // Irms = root mean square current
        // R = resistance  ,   L= inductance,  C= capacitor
        // Womega = angular frequency
        // Z = impendence (resistance offered by the combination of resistor, inductor, capacitor)
        // f = frequency
        // pf = power factor

        cout << "Xl = inductive resistance " << endl;
        cout << " Xc = capacitive resistance " << endl;
        cout << "Vrms = root mean square voltage" << endl;
        cout << "Irms = root mean square current " << endl;
        cout << "R = resistance  ,   L= inductance,  C= capacitor " << endl;
        cout << "Womega = angular frequency " << endl;
        cout << "Z = impendence (resistance offered by the combination of resistor, inductor, capacitor) " << endl;
        cout << "f = frequency " << endl;
        cout << "pf = power factor " << endl;

        cout << endl;
        cout << endl;

        cout << "enter the value of Vrms: ";
        cin >> Vrms;
        cout << "enter the value of Irms: ";
        cin >> Irms;
        cout << "enter the value of resistance in ohms: ";
        cin >> R;
        cout << "enter the value of capacitance in farad: ";
        cin >> C;
        cout << "enter the value of inductance: ";
        cin >> L;
        cout << "enter the value of frequency: ";
        cin >> f;

        // Calculating all Possible Results
        Vmax = Vrms * pow(2, 0.5);
        Imax = Irms * pow(2, 0.5);
        Womega = 2 * 3.14 * f;
        Xl = Womega * L;
        Xc = (1 / (Womega * C)) * pow(10, 6);
        Z = pow((pow(R, 2) + pow((Xl - Xc), 2)), 0.5);
        pf = R / Z;
        Power = Vrms * Irms * pf;

        cout << "\n****" << endl;

        // Printing all Possible Results

        cout << "the value of Vmax is " << Vmax << " volt " << endl;
        cout << "the value of Imax is " << Imax << " ampere" << endl;
        cout << "the value of angular frequency Womega is " << Womega << " rad/sec" << endl;
        cout << "the value of inductive reactance is " << Xl << " ohm" << endl;
        cout << "the value of capacitive rectance  in micro farad is " << Xc << " ohm" << endl;
        cout << "the value of impendence is " << Z << " ohm" << endl;
        cout << "the value of power factor is " << pf << endl;
        cout << "the value of power  is " << Power << " watt" << endl;
    }
    void RLC_capacitive_circuit()
    {
        cout << endl;
        cout << endl;
        cout << "as Xc is grater than Xl therefore RLC circuit behave's like  capacitive circuit" << endl;
        cout << endl;
        cout << "Xl = inductive resistance " << endl;
        cout << " Xc = capacitive resistance " << endl;
        cout << "Vrms = root mean square voltage" << endl;
        cout << "Irms = root mean square current " << endl;
        cout << "R = resistance  ,   L= inductance,  C= capacitor " << endl;
        cout << "Womega = angular frequency " << endl;
        cout << "Z = impendence (resistance offered by the combination of resistor, inductor, capacitor) " << endl;
        cout << "f = frequency " << endl;
        cout << "pf = power factor " << endl;

        cout << endl;

        cout << "enter the value of Vrms: ";
        cin >> Vrms;
        cout << "enter the value of Irms: ";
        cin >> Irms;
        cout << "enter the value of resistance in ohms: ";
        cin >> R;
        cout << "enter the value of capacitance in farad: ";
        cin >> C;
        cout << "enter the value of inductance: ";
        cin >> L;
        cout << "enter the value of frequency: ";
        cin >> f;

        // Calculating all Possible Results
        Vmax = Vrms * pow(2, 0.5);
        Imax = Irms * pow(2, 0.5);
        Womega = 2 * 3.14 * f;
        Xl = Womega * L;
        Xc = (1 / (Womega * C)) * pow(10, 6);
        Z = pow((pow(R, 2) + pow((Xc - Xl), 2)), 0.5);
        pf = R / Z;
        Power = Vrms * Irms * pf;

        cout << "\n****" << endl;

        // Printing all Possible Results

        cout << "the value of Vmax is " << Vmax << " volt " << endl;
        cout << "the value of Imax is " << Imax << " ampere" << endl;
        cout << "the value of angular frequency Womega is " << Womega << " rad/sec" << endl;
        cout << "the value of inductive reactance is " << Xl << " ohm" << endl;
        cout << "the value of capacitive rectance  in micro farad is " << Xc << " ohm" << endl;
        cout << "the value of impendence is " << Z << " ohm" << endl;
        cout << "the value of power factor is " << pf << endl;
        cout << "the value of power  is " << Power << " watt" << endl;
    }

    void RLC_purely_resistive_circuit()
    {
        cout << endl;
        cout << endl;
        cout << "as Xl = Xc  therefore RLC circuit behave's like purely resistive circuit" << endl;
        cout << "This is also called resonance condition" << endl;
        cout << "Xl = inductive resistance " << endl;
        cout << " Xc = capacitive resistance " << endl;
        cout << "Vrms = root mean square voltage" << endl;
        cout << "Irms = root mean square current " << endl;
        cout << "R = resistance  ,   L= inductance,  C= capacitor " << endl;
        cout << "Womega = angular frequency " << endl;
        cout << "Z = impendence (resistance offered by the combination of resistor, inductor, capacitor) " << endl;
        cout << "f = frequency " << endl;
        cout << "pf = power factor " << endl;

        cout << endl;
        cout << endl;

        Xl = Xc;

        cout << "enter the value of Vrms: ";
        cin >> Vrms;
        cout << "enter the value of Irms: ";
        cin >> Irms;
        cout << "enter the value of resistance in ohms: ";
        cin >> R;
        cout << "enter the value of capacitance in micro farad: ";
        cin >> C;
        cout << "enter the value of inductance: ";
        cin >> L;
        // cout << "enter the value of frequency: ";
        // cin >> f;

        // Calculating all Possible Results

        Vmax = Vrms * pow(2, 0.5);
        Imax = Irms * pow(2, 0.5);
        Womega = ((1 / pow(L * C, 0.5)) * pow(10, 3));
        Z = pow((pow(R, 2) + pow((Xl - Xc), 2)), 0.5);
        pf = R / Z;
        Power = Vrms * Irms * pf;

        cout << "\n****" << endl;
        // Printing all Possible Results

        cout << "the value of Vmax is " << Vmax << " volt" << endl;
        cout << "the value of Imax is " << Imax << " ampere" << endl;
        cout << "the value of angular frequency Womega is " << Womega << " rad/sec" << endl;
        // cout << "the value of inductive reactance is " << Xl<<endl;
        // cout << "the value of capacitive rectance is " << Xc<<endl;
        cout << "the value of impendence is " << Z << " ohm" << endl;
        cout << "the value of power factor is " << pf << endl;
        cout << "the value of power  is " << Power << " watt" << endl;
    }
};

int main()
{
    cout << "\n                                                           --------------------------------------------------------------------- " << endl;
    cout << "                                                                 Vishwakarma Institute Of Information Technology, Pune, 48" << endl;
    cout << "                                                                     Department Of Engg. And Applied Science : First Year" << endl;
    cout << "                                                                                   Project Presentation         " << endl;
    cout << "                                                                                           ON                   " << endl;
    cout << "                                                                        Resistor-Capacitor-Inductor problem solver      " << endl;
    cout << "                                                                ----------------------------------------------------------------- " << endl;
    cout << endl;
    cout << "                                                                                      Presented by :                                          " << endl;

    cout << "\n                                                            951: Arnav Umarkar    952: Udit Paniyar   955: Mrugank Shirurkar " << endl;

    cout << "                                                                    959: Kshipra Rudrawar       963: Aryan Phalke          " << endl;
    cout << endl;
    cout << "                                                                               Under the Guidence                                           " << endl;
    cout << "                                                                               Mrs. Sharada Desai Mam                                                " << endl;
    cout << "                                                                               Welcome To Our Project                                                     " << endl;
    cout << "                                                                ----------------------------------------------------------------- " << endl;
    cout << "                                                                             Press Any key to continue.....            ";
    getch();
    cout << endl;
    cout << "                                                                ----------------------------------------------------------------- " << endl;
    cout << "\n                                                                       Enter 1 for series connection of resistances " << endl;
    cout << "                                                                       Enter 2 for parallel connection of resistances " << endl;
    cout << "                                                                       Enter 3 for series connection of capacitors " << endl;
    cout << "                                                                       Enter 4 for parallel connection of capacitors " << endl;
    cout << "                                                                       Enter 5 for capacity of parallel plate capacitors " << endl;
    cout << "                                                                       Enter 6 for capacity of parallel plate capacitor taking k as dilectric constant " << endl;
    cout << "                                                                       Enter 7 for capacity of spherical capacitor " << endl;
    cout << "                                                                       Enter 8 for capacity of cylinderical capacitor " << endl;
    cout << "                                                                       Enter 9 for Finding force between parallel plate capacitor " << endl;
    cout << "                                                                       Enter 10 for RC Circuit " << endl;
    cout << "                                                                       Enter 11 for RCL circuit " << endl;
    cout << "                                                                       Enter 12 for exit " << endl;
    cout << "                                                                       Enter the option between 1 to 12 " << endl;
    cout << "                                                                ----------------------------------------------------------------- " << endl;

    // Creating Objects of the class
    resistance r1;
    capacitor c1;
    LRC l1;

    int value;
    cout << "\n                                                                       Enter The Option ";
    cin >> value;
    switch (value)
    {
    case 1:
        r1.series_resistance();
        break;
    case 2:
        r1.parallel_resistance();
        break;
    case 3:
        c1.series_capacitor();
        break;
    case 4:
        c1.parallel_capacitor();
        break;
    case 5:
        c1.Parallel_plate_capacity();
        break;
    case 6:
        c1.Parallel_plate_K_As_medium();
        break;
    case 7:
        c1.spherical_capacitor();
        break;
    case 8:
        c1.cylinderical_capacitance();
        break;
    case 9:
        c1.force();
        break;
    case 10:
    {
        int option;
        cout << "1 to enter the sequence at once. \n2 to enter the sequence one by one.\nplease enter...";
        cin >> option;

        if (option == 1) // For asking sequence
        {
            string ckt;
            cout << "Enter the sequence: ";
            cin >> ckt;
            cout << "\nThe sequence is: " << ckt << endl;
            switch_case(ckt);
        }
        else if (option == 2) // For taking sequence one by one
        {
            string ckt = ask_input();
            cout << "\nThe sequence is: " << ckt << endl;
            switch_case(ckt);
        }
    }
    break;
    case 11:
        cout << endl;
        cout << "You are in LCR circuit " << endl;

        int value;
        cout << endl;
        cout << "enter 1 for the case Xl > Xc " << endl;
        cout << "enter 2 for the case Xc > Xl " << endl;
        cout << "enter 3 for the case Xl = Xc " << endl;
        cout << "enter the your case: ";
        cin >> value;

        switch (value)
        {
        case 1:

            l1.RLC_inductive_circuit();
            break;

        case 2:

            l1.RLC_capacitive_circuit();
            break;

        case 3:
            l1.RLC_purely_resistive_circuit();
            break;

        case 4:
            break;
        }
    case 12:
        cout << "\n\n                                                                       We are coming out of program ";
        cout<<endl;
        cout<<endl;
        break;
    }
    return 0;
}