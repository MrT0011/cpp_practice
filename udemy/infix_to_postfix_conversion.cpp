/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <stack>
#include <string.h>

using namespace std;

map < char, int >outStackPre
{
  {
  '+', 1},
  {
  '-', 1},
  {
  '*', 3},
  {
  '/', 3},
  {
  '^', 6},
  {
  '(', 7},
  {
')', 0}};

map < char, int >inStakPre
{
  {
  '+', 2},
  {
  '-', 2},
  {
  '*', 4},
  {
  '/', 4},
  {
  '^', 5},
  {
'(', 0}};

int
isOperand (char c)
{
  if (c == '+' | c == '-' | c == '*' | c == '/' | c == '^' | c == '(' | c ==
      ')')
    return 0;
  return 1;
}

char *
InToPost (const char *infix)
{

  int i = 0, j = 0;
  stack < char >st;
  int len = strlen (infix);
  char *postfix = new char[len];

  while (infix[i] != '\0')
    {
      if (isOperand (infix[i]))
	postfix[j++] = infix[i++];
      else
	{
	  if (st.empty () || (outStackPre[infix[i]] > inStakPre[st.top ()]))
	    st.push (infix[i++]);
	  else
	    {
	      if (outStackPre[infix[i]] != inStakPre[st.top ()])
		{
		  postfix[j++] = st.top ();
		  st.pop ();
		}
	      else
		{
		  i++;
		  st.pop ();
		}
	    }
	}
    }

  while (!st.empty ())
    {
      postfix[j++] = st.top ();
      st.pop ();
    }

  postfix[j] = '\0';
  return postfix;
}

int
main ()
{
  const char *infix = "((a+b))*c-d^e^f";
  const char *postfix = InToPost (infix);

  cout << infix << endl;
  cout << postfix << endl;

  return 0;
}
