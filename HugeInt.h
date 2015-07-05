#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>

using namespace std;

class HugeInt{
	public:
		HugeInt();
		HugeInt(int in);
		HugeInt(string in);
		
		const HugeInt& operator =(const HugeInt & i);
		friend istream& operator >>(istream & in, HugeInt & i);
		friend ostream& operator <<(ostream & out, const HugeInt & i);
		friend HugeInt operator + (const HugeInt & i, const HugeInt & j);
		friend HugeInt operator - (const HugeInt & i, const HugeInt & j);
	private:
		string number;
};

