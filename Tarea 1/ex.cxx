#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main(){
    return 0;
}

double mean(vector<double> v){
    double suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma = suma + v[i];
    }
    return suma / v.size();
}

double variance(vector<double> v){
    double m = mean(v);
    double suma = 0;
    for (int i = 0; i < v.size(); i++) {
        double diff = v[i] - m;
        suma = suma + diff * diff;
    }
    return suma / v.size();
}

double pearson_r(vector<double> A, vector<double> B){
    double mA = mean(A);
    double mB = mean(B);
    double cov = 0;
    for (int i = 0; i < A.size(); i++) {
        cov = cov + (A[i] - mA) * (B[i] - mB);
    }
    cov = cov / A.size();
    return cov / (sqrt(variance(A)) * sqrt(variance(B)));
}

vector<char> dec_to_septapus(int n){
    if(n == 0) return {'0'};
    vector<char> result;
    while(n > 0){
        int r = n % 7;
        result.insert(result.begin(), '0' + r);
        n = n / 7;
    }
    return result;
}

vector<char> dec_to_octopus(int n){
    if(n == 0) return {'0'};
    vector<char> result;
    while(n > 0){
        int r = n % 8;
        result.insert(result.begin(), '0' + r);
        n = n / 8;
    }
    return result;
}

vector<char> dec_to_hexakaidecapus(int n){
    if(n == 0) return {'0'};
    vector<char> result;
    string digits = "0123456789abcdef";
    while(n > 0){
        int r = n % 16;
        result.insert(result.begin(), digits[r]);
        n = n / 16;
    }
    return result;
}

vector<char> septapus_to_dec(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 7 + (s[i] - '0');
    }
    vector<char> r;
    int n = result;
    if(n == 0) return {'0'};
    while(n > 0){
        r.insert(r.begin(), '0' + n % 10);
        n = n / 10;
    }
    return r;
}

vector<char> octopus_to_dec(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 8 + (s[i] - '0');
    }
    vector<char> r;
    int n = result;
    if(n == 0) return {'0'};
    while(n > 0){
        r.insert(r.begin(), '0' + n % 10);
        n = n / 10;
    }
    return r;
}

vector<char> hexakaidecapus_to_dec(vector<char> s){
    string digits = "0123456789abcdef";
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        int val = digits.find(s[i]);
        result = result * 16 + val;
    }
    vector<char> r;
    int n = result;
    if(n == 0) return {'0'};
    while(n > 0){
        r.insert(r.begin(), '0' + n % 10);
        n = n / 10;
    }
    return r;
}

vector<char> septapus_to_octopus(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 7 + (s[i] - '0');
    }
    return dec_to_octopus(result);
}

vector<char> septapus_to_hexakaidecapus(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 7 + (s[i] - '0');
    }
    return dec_to_hexakaidecapus(result);
}

vector<char> octopus_to_septapus(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 8 + (s[i] - '0');
    }
    return dec_to_septapus(result);
}

vector<char> octopus_to_hexakaidecapus(vector<char> s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result = result * 8 + (s[i] - '0');
    }
    return dec_to_hexakaidecapus(result);
}

vector<char> hexakaidecapus_to_septapus(vector<char> s){
    string digits = "0123456789abcdef";
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        int val = digits.find(s[i]);
        result = result * 16 + val;
    }
    return dec_to_septapus(result);
}

vector<char> hexakaidecapus_to_octopus(vector<char> s){
    string digits = "0123456789abcdef";
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        int val = digits.find(s[i]);
        result = result * 16 + val;
    }
    return dec_to_octopus(result);
}
