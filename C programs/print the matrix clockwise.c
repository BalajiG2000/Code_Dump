#include <stdio.h>
#include<stdlib.h>
int row_i ();
int row_d ();
int col_i ();
int col_d ();
int a[10][10], i, j, r, c, to = 0, i1 = 0, j2 = 0;
int
main ()
{
  printf ("enter the row and column no\n");
  scanf ("%d%d", &r, &c);
  printf ("enter the numbers\n");
  for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
	{
	  scanf ("%d", &a[i][j]);
	}
    }
  i = 0;
  j = 0;
  //printf("%d",a[i][j]);
  col_i ();
  return 0;
}

int
col_i ()
{
  if (to >= r * c)
    {
      exit (0);
    }
  else
    {
        j2=j;
      while (j < c - j2)
	{
	  printf ("%d", a[i][j]);
	  j++;
	  to++;
	}
    }
  j--;
  i++;
  row_i ();
}

int
row_i ()
{
  if (to == r * c)
    {
      exit (0);
    }
  else
    {
      i1 = i;
      while (i <= r - i1)
	{
	  printf ("%d", a[i][j]);
	  i++;
	  to++;
	}
    }
  i--;
  j--;
  col_d ();
}

int
col_d ()
{
  if (to == r * c)
    {
      exit (0);
    }
  else
    {
        j2=j+1;
      while (j >= c - j2 - 1)
	{
	  printf ("%d", a[i][j]);
	  j--;
	  to++;
	}
    }
  j++;
  i--;
  row_d ();
}

int
row_d ()
{
  if (to == r * c)
    {
      exit (0);
    }
  else
    {
      i1 = i;
      while (i >= r - i1 - 1)
	{
	  printf ("%d", a[i][j]);
	  to++;
	  i--;
	}
    }
  j++;
  i++;
  col_i ();
}

