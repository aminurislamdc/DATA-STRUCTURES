#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt=0, bn=1;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        if(a[i]>a[i+1]){
            bn--;
            break;
        }
    }
    if(bn){
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                if(a[j+1]>a[j]){
                    swap(a[j+1],a[j]);
                }
            }
            cnt++;
            for(int i=0; i<n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        cout << cnt << endl;
        for(int i=0; i<n; i++){
            cout << a[i] << " ";
        }
    }

    return 0;
}

