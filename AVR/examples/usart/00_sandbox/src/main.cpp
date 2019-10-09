#include <util.h>
#include <usart/usart0.h>

using namespace Usart;

void init(void)
{
	usart0.init({ TIO_BAUD });
	stdout = usart0.stream();

	sei();
}

int main(void)
{
	init();

	while (true)
		putchar('\n');
}
