int binky(int x)
{
   int y = x + 2;
   return y;
}

int winky(int x)
{
   int y = binky(x+1);
   return x+y;
}

int main()
{
   int y = winky(2);
   return y;
}

