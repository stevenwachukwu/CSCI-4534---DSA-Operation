/*This program is my solution for the last question of HW#3. This program was created to see how the DSA algorithm works for a different set of inputs.
Author: Steve Nwachukwu
Course: Cryptography and Data Security
Semester: Spring 2024
Professor: Chandra
*/

#include <iostream>
#include <cmath>

using namespace std;

long long ModExpoFunction(long long base, long long exponent, long long modulo) {
	long long solution = 1;
	base = base % modulo;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			solution = (solution * base) % modulo;
		}
		exponent = exponent >> 1;
		base = (base * base) % modulo;
	}
	return solution;
} //the function used to calculate the modular exponentiation

void DSACalculation(long long p, long long q, long long h, long long x, long long k, long long H, long long &g, long long &y, long long &r, long long &s) {
	long long kInverse = 1;
	while (((k * kInverse) % q) != 1) {
		kInverse = (kInverse + 1) % q;
	}

	g = ModExpoFunction(h, (p - 1) / q, p);
	y = ModExpoFunction(g, x, p);

	r = 0;
	s = 0;

	while (r == 0 || s == 0) {
		r = ModExpoFunction(g, k, p) % q;
		s = (kInverse * (H + (x * r))) % q;
	}
	cout <<"\nThe printout of r: " << r << endl;
	cout << "\nThe printout of s: " << s << endl;
	
} //the function used to calculate DSA


bool signatureVerification(long long p, long long q, long long g, long long y, long long r, long long s, long long H) {
	long long w = 1;
	long long sInverse = 1;
	while (((s * sInverse) % q) != 1) {
		w++;
		sInverse = (sInverse + 1) % q;
	}
	long long U1 = (H * w) % q;
	long long U2 = (r * w) % q;

	long long V = ((ModExpoFunction(g, U1, p) * ModExpoFunction(y, U2, p)) % p) % q;

	cout << "\nThe result of w: " << w << endl;
	cout << "\nThe result of U1: " << U1 << endl;
	cout << "\nThe result of U2: " << U2 << endl;
	cout << "\nThe result of v: " << V << endl;
	return V == r;
} //the function for signature verification

int main() {
	cout << "The first results: " << endl;
	long long P1 = 7;
	long long Q1 = 3; 
	long long H1 = 3;
	long long X1 = 2;
	long long K1 = 1;
	long long HM1 = 3;
	long long HM2 = 4;
	long long g1;
	long long y1;
	long long r1;
	long long s1;
	
	DSACalculation(P1, Q1, H1, X1, K1, HM1, g1, y1, r1, s1);
	cout << "\nThe result of g: " << g1 << endl;
	cout << "\nThe result of y: " << y1 << endl;
	
	bool solution1 = signatureVerification(P1, Q1, g1, y1, r1, s1, HM1);
	cout << "\nThe signature for H(M1) is valid (True or False?): " << (solution1 ? "True" : "False") << endl;
	bool solution2 = signatureVerification(P1, Q1, g1, y1, r1, s1, HM2);
	cout << "\nThe signature for H(M2) is valid (True or False?): " << (solution2 ? "True" : "False") << endl;

	cout << "\nThe second results: " << endl;
	long long P2 = 47;
	long long Q2 = 23;
	long long H2 = 5;
	long long X2 = 7;
	long long K2 = 13;
	long long newHM1 = 5;
	long long newHM2 = 4;
	long long g2;
	long long y2;
	long long r2;
	long long s2;
	
	DSACalculation(P2, Q2, H2, X2, K2, newHM1, g2, y2, r2, s2);
	cout << "\nThe result of g: " << g2 << endl;
	cout << "\nThe result of y: " << y2 << endl;
	bool solution3 = signatureVerification(P2, Q2, g2, y2, r2, s2, newHM1);
	cout << "\nThe signature for H(M1) is valid (True or False?): " << (solution3 ? "True" : "False") << endl;
	bool solution4 = signatureVerification(P2, Q2, g2, y2, r2, s2, newHM2);
	cout << "\nThe signature for H(M2) is valid (True or False?): " << (solution4 ? "True" : "False") << endl;

	cout << "\nThe third results: " << endl;
	long long P3 = 9975; 
	long long Q3 = 103; 
	long long H3 = 2; 
	long long X3 = 2347; 
	long long K3 = 6791; 
	long long newestHM1 = 4323; 
	long long newestHM2 = 8767; 
	long long g3;
	long long y3;
	long long r3;
	long long s3;

	DSACalculation(P3, Q3, H3, X3, K3, newestHM1, g3, y3, r3, s3);
	cout << "\nThe result of g: " << g3 << endl;
	cout << "\nThe result of y: " << y3 << endl;
	bool solution5 = signatureVerification(P3, Q3, g3, y3, r3, s3, newestHM1);
	cout << "\nThe signature for H(M1) is valid (True or False?): " << (solution5 ? "True" : "False") << endl;
	bool solution6 = signatureVerification(P3, Q3, g3, y3, r3, s3, newestHM2);
	cout << "\nThe signature for H(M2) is valid (True or False?): " << (solution6 ? "True" : "False") << endl;
	
	return 0;
}
