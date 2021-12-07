#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main ()
{
    int n, i, res_xl, res_xr, res_il, res_ir, zm, res_i, res_x;
    double result;
    string s1, s2, p, s;
    vector <string> xleft;
    vector <string>::iterator it_xl;
    vector <string> xright;
    vector <string>::iterator it_xr;
    vector <string> intleft;
    vector <string>::iterator it_il;
    vector <string> intright;
    vector <string>::iterator it_ir;
    cin >> n;
    while (n--)
    {
        res_xl = res_xr = res_il = res_ir = res_i = res_x = result = 0;
        xleft.clear();
        xright.clear();
        intleft.clear();
        intright.clear();

        cin >> s;
        i = s.find("=");
        s1 = s.substr(0, i);
        s2 = s.substr(i + 1, s.size() - s1.size() - 1);
        p = "";
        for (i = 0; i < s1.size(); i++) //left
        {
            if (s1[i] == '+' || s1[i] == '-')
            {
                if (p != "")
                {
                    if (p.find('x') == string::npos) intleft.push_back(p); //no "x" found
                    else xleft.push_back(p);
                    p = "";
                }
            }
            p += s1[i];
        }
        if (p != "")
        {
            if (p.find('x') == string::npos) intleft.push_back(p); //the last element
            else xleft.push_back(p);
        }
        p = "";
        for (i = 0; i < s2.size(); i++) //right
        {
            if (s2[i] == '+' || s2[i] == '-')
            {
                if (p != "")
                {
                    if (p.find('x') == string::npos) intright.push_back(p); //no "x" found
                    else xright.push_back(p);
                    p = "";
                }
            }
            p += s2[i];
        }
        if (p != "")
        {
            if (p.find('x') == string::npos) intright.push_back(p); //the last element
            else xright.push_back(p);
        }

        //erasing x-es to solve equations in vectors
        for(it_xl = xleft.begin(); it_xl != xleft.end(); it_xl++)
        {
            (*it_xl).erase((*it_xl).begin() + (*it_xl).find('x')); //erase przyjmuje iterator, a find zwraca pozycje
            if (*it_xl == "" || *it_xl == "+" || *it_xl == "-" )
            {
                (*it_xl) += "1";
            }
        }
        for(it_xr = xright.begin(); it_xr != xright.end(); it_xr++)
        {
            (*it_xr).erase((*it_xr).begin() + (*it_xr).find('x'));
            if (*it_xr == "" || *it_xr == "+" || *it_xr == "-" )
            {
                (*it_xr) += "1";
            }
        }

        //<string> vector to <int> vector
        for(it_xl = xleft.begin(); it_xl != xleft.end(); it_xl++)
        {
            zm = stoi(*it_xl);
            res_xl += zm;
        }
        for(it_xr = xright.begin(); it_xr != xright.end(); it_xr++)
        {
            zm = stoi(*it_xr);
            res_xr += zm;
        }
        res_xr = 0 - res_xr;
        for(it_il = intleft.begin(); it_il != intleft.end(); it_il++)
        {
            zm = stoi(*it_il);
            res_il += zm;
        }
        res_il = 0 - res_il;
        for(it_ir = intright.begin(); it_ir != intright.end(); it_ir++)
        {
            zm = stoi(*it_ir);
            res_ir += zm;
        }
        res_x = res_xl + res_xr;
        if (res_x == 0)
        {
            cout << "NO\n";
            continue;
        }
        res_i = res_ir + res_il;
        result = ((double)res_i)/res_x;
        cout << setprecision (4) << result << "\n";
    }


    return 0;
}
