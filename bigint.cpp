#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BigInt{
    string digits;

public:
    int flaggg=0;
    BigInt(unsigned long long n = 0);
    BigInt(string );
    BigInt(BigInt &);


    friend int sizee(const BigInt &);



    BigInt &operator=(const BigInt &);


    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator==(const BigInt &, const BigInt &);



    friend ostream &operator<<(ostream &,const BigInt &);



};

BigInt::BigInt(string  s){
    digits = "";
    int n = s.size();
    if(s[0]=='-'){
        flaggg=1;
        for (int i = n - 1; i > 0;i--){

            if(!isdigit(s[i]))

                throw("bad input");
            digits.push_back(s[i] - '0');
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {

            if (!isdigit(s[i]))

                throw ("bad input");
            digits.push_back(s[i] - '0');
        }
    }
}
BigInt::BigInt(unsigned long long r){
    do{
        digits.push_back(r % 10);
        r /= 10;
    } while (r);
}

BigInt::BigInt(BigInt & m){
    digits = m.digits;
}


int sizee(const BigInt & m){
    return m.digits.size();
}



BigInt &BigInt::operator=(const BigInt &k){
    digits = k.digits;
    return *this;
}

BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = sizee(a), m = sizee(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = sizee(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}




BigInt operator+(const BigInt &a, const BigInt &b){

    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = sizee(a), m = sizee(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
BigInt &operator-=(BigInt&a,const BigInt &b){
    if(a < b)
        throw("bad input");
    int n = sizee(a), m = sizee(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
                    t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
                n--;
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

bool operator==(const BigInt &a, const BigInt &b){
    return a.digits == b.digits;
}

ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}
void test1 (){
    string num1="123456789012345678901234567890";
    string num2="113456789011345678901134567890";
    string e_num3="236913578023691357802369135780";
    BigInt s(num1);
    BigInt r(num2);
    BigInt g;
    BigInt e(e_num3);
    cout<<"num 1 = "<<num1<<endl;
    cout<<"num 2 = "<<num2<<endl;

    if(r.flaggg==1& s.flaggg==0){
        g=s-r;
    }
    else if(s.flaggg==1&r.flaggg==0){
        g= r-s;
    }
    else {
        g= s + r;
    }

    if(e==g){
        cout<<"result is ="<<g<<endl;
        cout<<"test 1 passed"<<endl;
    }
    else{
        cout<<"test 1 fail";
    }

};
void test2 (){
    string num1="2350000000000000000000000000";
    string num2="-1350000000000000000000000000";
    string e_num3="1000000000000000000000000000";
    BigInt s(num1);
    BigInt r(num2);
    BigInt g;
    BigInt e(e_num3);
    cout<<"num 1 = "<<num1<<endl;
    cout<<"num 2 = "<<num2<<endl;

    if(r.flaggg==1& s.flaggg==0){
        g=s-r;
    }
    else if(s.flaggg==1&r.flaggg==0){
        g= r-s;
    }
    else {
        g= s + r;
    }

    if(e==g){
        cout<<"result is ="<<g<<endl;
        cout<<"test 2 passed"<<endl;
    }
    else{
        cout<<"test 2 fail";
    }
};
void test3 (){
    string num1="78787878787878787878787878787";
    string num2="32323232";
    string e_num3="78787878787878787878820202019";
    BigInt s(num1);
    BigInt r(num2);
    BigInt g;
    BigInt e(e_num3);
    cout<<"num 1 = "<<num1<<endl;
    cout<<"num 2 = "<<num2<<endl;

    if(r.flaggg==1& s.flaggg==0){
        g=s-r;
    }
    else if(s.flaggg==1&r.flaggg==0){
        g= r-s;
    }
    else {
        g= s + r;
    }

    if(e==g){
        cout<<"result is ="<<g<<endl;
        cout<<"test 3 passed"<<endl;
    }
    else{
        cout<<"test 3 fail";
    }};
void test4 (){
    string num1="-64646565";
    string num2="7575757575";
    string e_num3="7511111010";
    BigInt s(num1);
    BigInt r(num2);
    BigInt g;
    BigInt e(e_num3);
    cout<<"num 1 = "<<num1<<endl;
    cout<<"num 2 = "<<num2<<endl;

    if(r.flaggg==1& s.flaggg==0){
        g=s-r;
    }
    else if(s.flaggg==1&r.flaggg==0){
        g= r-s;
    }
    else {
        g= s + r;
    }

    if(e==g){
        cout<<"result is ="<<g<<endl;
        cout<<"test 4 passed"<<endl;
    }
    else{
        cout<<"test 4 fail";
    }
};
void test5 (){
    string num1="-6666666666666666";
    string num2="-1111111111111111";
    string e_num3="7777777777777777";
    BigInt s(num1);
    BigInt r(num2);
    BigInt g;
    BigInt e(e_num3);
    cout<<"num 1 = "<<num1<<endl;
    cout<<"num 2 = "<<num2<<endl;

    if(r.flaggg==1& s.flaggg==0){
        g=s-r;
    }
    else if(s.flaggg==1&r.flaggg==0){
        g= r-s;
    }
    else {
        g= s + r;
    }

    if(e==g){
        cout<<"result is ="<<g<<endl;
        cout<<"test 5 passed"<<endl;
    }
    else{
        cout<<"test 5 fail";
    }
};

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

}
