#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        // cout<<n;
        int n_fi{};
        int ty[n];
        int temp;
        for (int i = 0; i < n; i++){
            cin >> temp;
            if (temp == 0)
                n_fi++;
            ty[i] = temp;
        }
        int fi_dmg[n_fi];
        int fr_dmg[n - n_fi];
        int temp2;
        int cntfi{0}, cntfr{0};
        for (int i = 0; i < n; i++){
            cin >> temp2;
            if (ty[i] == 0){
                fi_dmg[cntfi] = temp2;
                cntfi++;
            }
            else if (ty[i] == 1){
                fr_dmg[cntfr] = temp2;
                cntfr++;
            }
        }
        /*
                for(int i = 0; i < n - n_fi; i++)
                {
                    cout<<fr_dmg[i]<<" "<<i<<" ";
                }*/

        sort(fi_dmg, fi_dmg + n_fi, greater<int>());
        sort(fr_dmg, fr_dmg + n - n_fi, greater<int>());
        int n_dub;
        if (n_fi != n - n_fi)
            n_dub = min(n_fi, n - n_fi);
        else
            n_dub = n_fi - 1;

        int left;
        int n_left;
        if (n_fi > n - n_fi){
            left = 0;
            n_left = 2 * n_fi - n;
        }
        else if (n_fi < n - n_fi){
            left = 1;
            n_left = n - 2 * n_fi;        }
        else
        {
            if (fi_dmg[n_fi - 1] >= fr_dmg[n - n_fi - 1])
                left = 1;
            else if (fi_dmg[n_fi - 1] < fr_dmg[n - n_fi - 1])
                left = 0;
            n_left = 1;
        }

        // cout<<n_left<<" "<<"\n";

        long long sum{};
        if (left == 0)
        {
            for (int i = 0; i < n_fi; i++)
            {
                if (i < n_fi - n_left)
                {
                    sum += 2 * fi_dmg[i];
                }
                else
                {
                    sum += fi_dmg[i];
                }
            }
            for (int i = 0; i < n - n_fi; i++)
            {
                sum += 2 * fr_dmg[i];
            }
        }
        else if (left == 1)
        {
            for (int i = 0; i < n - n_fi; i++)
            {
                if (i < n - n_fi - n_left)
                {
                    sum += 2 * fr_dmg[i];
                    // cout<<2* fr_dmg[i]<<" ";
                }
                else
                {
                    sum += fr_dmg[i];
                    // cout<<2* fr_dmg[i]<<" ";
                }
            }
            for (int i = 0; i < n_fi; i++)
            {
                sum += 2 * fi_dmg[i];
            }
        }
        cout << sum << "\n";
    }
}
