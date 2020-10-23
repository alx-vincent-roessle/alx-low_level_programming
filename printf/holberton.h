typedef struct op
{
	char	op;
	int	(*f)(va_list args);
}	op_t;

int _printf(const char *format, ...);
