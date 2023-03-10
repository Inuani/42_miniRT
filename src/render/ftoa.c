
#include "../../includes/minirt.h"

void	reverse(char* str, int len)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = len - 1;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

void	putneg(char *str)
{
	int		i;
	char	c;
	char	temp;

	i = 0;
	c = str[i];
	str[i] = '-';
	while (str[++i])
	{
		temp = str[i];
		str[i] = c;
		c = temp;
	}
	str[++i] = '0';
	str[i] = '\0';
}

int	intToStr(int x, char str[], int d)
{
	int i;

	i = 0;
	if (x < 0)
		x = -x;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

char	*floatToString(float n, char* res)
{
	int ipart = (int)n;
	float fpart = n - (float)ipart;
	int i = intToStr(ipart, res, 0);
	res[i] = '.';
	fpart = fpart * pow(10, 1);
	intToStr((int)fpart, res + i + 1, 1);
	if (n < 0)
		putneg(res);
	return (res);
}
