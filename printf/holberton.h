typedef struct op
{
	char	op;
	void	(*f)(va_list args);
}	op_t;