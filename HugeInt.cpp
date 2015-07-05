#include "HugeInt.h"

using namespace std;

const HugeInt& HugeInt::operator =(const HugeInt & i){
        number=i.number;
        return *this;
}

istream& operator >>(istream & in, HugeInt & i){
        in >> i.number;
        return in;
}

ostream& operator <<(ostream & out, const HugeInt & i){
        out << i.number;
        return out;
}

HugeInt operator + (const HugeInt & i, const HugeInt & j){
        HugeInt temp;
        int a=i.number.length()-1;
        int b=j.number.length()-1;
        int add=1;

        for( ;((a>=0)&&(b>=0)); --a, --b){
                temp.number=static_cast<char>(i.number[a]+j.number[b]+add-48)+temp.number;
                if(temp.number[0]>57){
                        temp.number[0]-=10;
                        add=1;
                }
                else
                        add=0;
        }

        if(a>=0){
                temp.number.insert(0, i.number.substr(0, a+1));
                temp.number[a]+=add;
        }
        else if(b>=0){
                temp.number.insert(0, j.number.substr(0, b+1));
                temp.number[b]+=add;
        }
        else if(add==1)
                temp.number="1"+temp.number;

        return temp;
}

HugeInt operator - (const HugeInt & i, const HugeInt & j){
        HugeInt temp;
        temp.number=i.number;
        int k;
        int a=temp.number.length()-1;
        int b=j.number.length()-1;
        for(; ((a>=0)&&(b>=0)); --a, --b){
                if(temp.number[a]<j.number[b]){
                        k=1;
                        while(temp.number[a-k]==48){
                                temp.number[b-k]+=9;
                                k++;
                        }
                        temp.number[a-k]-=1;
                        temp.number[a]=temp.number[a]-j.number[a]+58;
                }
                else
                        temp.number[a]=temp.number[a]-j.number[b]+48;
        }

        while((temp.number[0]==48) && (temp.number.length()>1))
                temp.number.erase(0,1);

        return temp;
}

HugeInt::HugeInt(){
        number="";
}

HugeInt::HugeInt(int in){
        number = to_string(in);
}
HugeInt::HugeInt(string in){
        number = in;
}
