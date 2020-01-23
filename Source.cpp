#include <iostream>
#include <string>

std::string G_TMP_TERN = "";
std::string G_TMP_DEC = "";
double G_TMP;

void setup(){
    for(int x  = 13; x > 0; x--)
    pinmode(x, OUTPUT);
}

namespace TMP {
   
    void convert(int TMP, std::string& TMPS) // Converts Decimal, raw TMP to a string G_TMP_TERN
    {   
        TMPS = ""; //resets the value as this gets called a lot

        if (TMP == 0) { // returns 0 if the val is 0
            TMPS = "0";
            return;
        }

        int x = TMP % 3; //Initiates X and defines it as TMP's Remainder, important for it gets recursive
        TMP /= 3;        //
        if (x < 0)
            TMP += 1;
        convert(TMP, TMPS);
        TMPS += std::to_string(x < 0 ? x - 3 : x); // adds the value after every attempt
        return; // returns aftermodifying the value
    }

    void updatelighting(std::string& TMPS, int tmp, const int& ln) {
        TMP::convert((int)tmp, TMPS);
    
        for (int x = ln - TMPS.length(); x > 0; x--) {
                TMPS.insert(0, "0");
         }
     
        for (int i = 0; i <= TMPS.length()-1; i++) { // gets length, finds values
            switch (TMPS[i]) { // switch case to find whether th 012 corrosponds to an LED. Will add error handling by flashing soon
            case '1': std::cout << "half\n";  continue;
            case '2': std::cout << "on\n"; digitalWrite(i, HIGH); continue;
            default: std::cout << "off\n"; digitalWrite(i, LOW);
            }
        }
    }
}
int main()
{
    setup();
    
    while (true){
    std::cin >> (G_TMP); //takes an imput from user instead of a thermometer,for a  proof of concept
    TMP::updatelighting(G_TMP_TERN, (int)G_TMP, 10); //calls this, which should be done while true but my computer would shit 
    std::cout << G_TMP_TERN <<"\n\n";
    std::cout << (G_TMP - (int)G_TMP) * 100 << "\n\n";
    TMP::updatelighting(G_TMP_DEC, ((int)(G_TMP * 100) % 100), 5);
    std::cout << G_TMP_DEC;
    }
}
