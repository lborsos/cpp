#include <iostream>

using namespace std;

int sol[20], n;

int verify(int pos){
    return 1;
}

void print(){
    for(int i=0; i<n; i++)
        cout << sol[i];
    cout << endl;
}

void back(int pos){
    if(pos==n) print();
    else
        for(int i=0; i<4; i++){
            sol[pos] = i;
            if (verify(pos)) back(pos+1);
        }

}

int main()
{
    cin >> n;
    back(0);
    return 0;
}
