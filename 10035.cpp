#include <bits/stdc++.h>

using namespace std;

string int_to_string( int a )
{
  stringstream b;
  b << a;
  return b.str();
}

int main()
{
  string a , b;
  int ans , carry , i, j;
  while( cin >> a >> b , a != "0" || b != "0" )
  {
    ans = carry = 0;
    i = a.size() - 1;
    j = b.size() - 1;
    while( i >= 0 && j >= 0 )
    {
      if( ( ( int )a[i] - '0' ) + ( ( int )b[j] - '0' ) + carry >= 10 )
      {
        ++ans;
        carry = int_to_string( ( ( int )a[i] - '0' ) + ( ( int )b[j] - '0' ) + carry )[0] - '0';
      }
      else
        carry = 0;
      --i;
      --j;
    }
    while( i >= 0 )
    {
      if( ( ( int ) a[i] - '0' ) + carry >= 10 )
      {
        ++ans;
        carry = int_to_string( ( ( int ) a[i] - '0' ) + carry )[0] - '0';
      }
      else
        carry = 0;
      --i;
    }
    while( j >= 0 )
    {
      if( ( ( int ) b[j] - '0' ) + carry >= 10 )
      {
        ++ans;
        carry = int_to_string( ( ( int ) b[j] - '0' ) + carry )[0] - '0';
      }
      else
        carry = 0;
      --j;
    }
    if( !ans )
      cout << "No carry operation.\n";
    else if( ans == 1 )
      cout << "1 carry operation.\n";
    else
      cout << ans << " carry operations.\n";
  }
  return 0;
}
