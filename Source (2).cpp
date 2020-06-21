#include"graphics.h"

class graph
{
public:
	graph(int n, int m);
	void cover() const;
private:
	void graphh() const;
	int n, m;
};
graph::graph(int n, int m)
{
	this->n = n;
	this->m = m;
}

void graph::graphh() const
{
	int i, l = 0, z, o = 11, v = 5, b; bool t = false;
	initgraph();
	clrscr();
	if (n % 2 == 0 && m % 2 == 0) { t = true; }
	for (i = 0; i < n; i++)
	{
		if (i == n - 2) o = o + m - 2;
		if (i == n - 1) o = o + m;
		if (i % 2 == 0) v++;
		z = 0; b = 1;
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1 && j == m - 2) o--;
			if (j % 2 == 0) b++;
			setcolor(0);
			circle(100 + z, 100 + l, 20);
			if (j < (m - 1))
			{
				if ((j == m - 2 || i == n - 1) && t == true) setcolor(o);
				else 
					setcolor(b);
				line(120 + z, 100 + l, 130 + z, 100 + l);		
			}
			if (i < (n - 1))
			{
				if ((j == m - 1 || i == n - 2) && t == true)
					if (i == n - 2 && j == m - 2) { o--; setcolor(o); o += 2; }
					else
						setcolor(o);
				else setcolor(v);
				line(100 + z, 120 + l, 100 + z, 130 + l);		
			}
			z += 50;
			if (i >= n - 2) o--;
		}
		l += 50; o--;
	}
}

void graph::cover() const
{
	graphh();
}



void main()
{
	int n, m;
	do {
		std::cout << "m=";
		std::cin >> m;
		std::cout << "n=";
		std::cin >> n;
		if ((n % 2 == 0 && m % 2 != 0) || (n % 2 != 0 && m % 2 == 0) || (n == 1 && m == 1) || n <= 0 || m <= 0);
		std::cout << "WE can't cover" << std::endl;
	} while ((n % 2 == 0 && m % 2 != 0) || (n % 2 != 0 && m % 2 == 0) || (n == 1 && m == 1) || n <= 0 || m <= 0);
	graph ob(m, n);
	ob.cover();

}