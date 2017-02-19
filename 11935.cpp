#include <bits/stdc++.h>

using namespace std;

struct op
{
    int par,time;
    bool gas,mech,leak,fc,goal;

    op()
    {
        gas = mech = leak = fc = goal = false;
        par = -1;
    }

};

double use(int diff , int fc)
{
    return double(diff)*double(fc) / 100.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line , bas;
    double llevo , ans;
    int diff,leak,fc;
    while(getline(cin , line) , line != "0 Fuel consumption 0")
    {
        vector < op > rec;
        stringstream a(line);
        op abc;
        abc.fc = true;
        a >> abc.time;
        a >> bas >> bas >> abc.par;
        rec.push_back(abc);
        while(getline(cin , line))
        {
            op nuevo;
            stringstream ss(line);
            ss >> nuevo.time >> bas;
            if(bas == "Goal")
            {
                nuevo.goal = true;
                rec.push_back(nuevo);
                break;
            }
            else if(bas == "Leak")
                nuevo.leak = true;
            else if(bas == "Gas")
                nuevo.gas = true;
            else if(bas == "Mechanic")
                nuevo.mech = true;
            else
            {
                nuevo.fc = true;
                ss >> bas >> nuevo.par;
            }
            rec.push_back(nuevo);
        }
        ans = -1e7;
        llevo = 0.0;
        leak = 0;
        fc = rec[0].par;
        for(int i = 1 ; i < rec.size() ; ++i)
        {
            diff = rec[i].time - rec[i-1].time;
            llevo += use(diff , fc);
            llevo += leak*diff;
            if(rec[i].mech)
                leak = 0;
            else if(rec[i].leak)
                ++leak;
            else if(rec[i].fc)
                fc = rec[i].par;
            else if(rec[i].goal || rec[i].gas)
            {
                ans = max(ans , llevo);
                llevo = 0.0;
            }
        }
        cout << fixed << setprecision(3) << ans << '\n';
    }
    return 0;
}
