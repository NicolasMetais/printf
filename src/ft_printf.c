
#include <stdio.h>
#include "./../include/printf.h"

t_printf	*init(t_printf *config)
{
	config->percent = 0;
	config->len = 0;
	config->sign = 0;
	return (config);
}

t_printf	*countformatspecifiers(const char *format, t_printf *config)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			config->percent += 1;
		i++;
	}
	i = 0;
	while (i < (size_t)config->percent)
	{
		va_arg(config->arg, void *);
		config->len += 1;
		i++;
	}
	if (config->len != config->percent)
		return (NULL);
	if (config->len == 0 && config->percent == 0)
		return (NULL);
	if (config->percent == 0)
		return (NULL);
	return(NULL);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*config;

	config = ft_calloc(1, sizeof(*config));
	if (!config)
	{
		free(config);
		return (-42);
	}
	init(config);
	va_start(config->arg, format);
	countformatspecifiers(format, config);
	return (0);
}

int main(void)
{
	ft_printf("c");
	//printf("c");
}