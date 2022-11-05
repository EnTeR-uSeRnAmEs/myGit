#ifndef __MY_STRING
#define __MY_STRING
#include <iostream>
using namespace std;
class String
{
public:
	String(const char *s = ""); //

	String(const String &str);

	String(const char c, int n = 1); //

	String(const String &Str, int pos, int n = 0);

	~String();

	bool empty();

	int length() const;

	int capacity() const;

	String substr(int pos, int n = 0) const;
	// String substr(int pos) const;

	const char *c_str();

	String &insert(int pos, const String &Str); //

	int find(const String &Str) const;

	String &replace(int pos, int n, const String &Str);

	String &erase(int pos, int n = 0); //

	String &trim();

	String &operator+=(const String &Str);

	char &operator[](int index);

	String &operator=`(const String &Str);

	friend String operator+(const String &Str1, const String &Str2);
	friend bool operator==(const String &Str1, const String &Str2);
	friend bool operator!=(const String &Str1, const String &Str2);
	friend bool operator>(const String &Str1, const String &Str2);	//
	friend bool operator>=(const String &Str1, const String &Str2); //
	friend bool operator<(const String &Str1, const String &Str2);	//
	friend bool operator<=(const String &Str1, const String &Str2); //

	friend ostream &operator<<(ostream &out, const String &Str); //
	friend istream &operator>>(istream &in, String &Str);		 //

private:
	void fitmem(char *s);
	void fitmem(const char *s);
	char *str = NULL;
};

#endif