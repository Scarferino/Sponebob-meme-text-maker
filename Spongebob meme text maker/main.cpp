#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream infile;
    std::ofstream outfile;
    std::stringstream textStream;
    std::string text;

    std::cout << "Put your text in the input.txt file, save the file, then press enter.";
    std::cin.get();

    infile.open("input.txt");
    outfile.open("output.txt");

    textStream << infile.rdbuf();
    text = textStream.str();

    if(outfile.is_open() && infile.is_open())
    {

        int capSwitch{};

        for(int i{0};i<text.length();i++)
            {
                capSwitch = (i+1)%2;
                if(capSwitch == 1)
                {
                    if(text[i]>=97 && text[i]<=122)
                    {
                        text[i] -= 32;
                    }
                }
                else if(capSwitch == 0)
                {
                    if(text[i]>=65 && text[i]<=90)
                    {
                        text[i] += 32;
                    }
                }
            }

            outfile << text;
    }
        outfile.close();
        infile.close();

    std::cout << "You can find the transformed text in the output.txt file.";
    std::cin.get();
}
