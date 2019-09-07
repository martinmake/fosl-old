#ifndef _PIN_PIN_H_
#define _PIN_PIN_H_

#include <inttypes.h>
#include <avr/io.h>

enum class Port : uint8_t
{
	B, C, D
};
enum class Direction : uint8_t
{
	INPUT, OUTPUT
};
enum class State : bool
{
	LOW, HIGH
};

template <Port port, uint8_t index, Direction direction = Direction::OUTPUT>
class Pin
{
	public:
		Pin(void);

	public:
		void set  (void);
		void clear(void);
		bool is_high(void);
		bool is_low (void);

		void make_input (void);
		void make_output(void);
		bool is_input (void);
		bool is_output(void);

	public:
		Pin& operator=(State state);
		operator State(void);
};

template <Port port, uint8_t index, Direction direction>
Pin<port, index, direction>::Pin(void)
{
	switch (direction)
	{
		case Direction::OUTPUT: make_output(); break;
		case Direction:: INPUT: make_input (); break;
	}
}

template <Port port, uint8_t index, Direction direction>
Pin<port, index, direction>& Pin<port, index, direction>::operator=(State state)
{
	switch (state)
	{
		case State::HIGH: set  (); break;
		case State::LOW:  clear(); break;
	}

	return *this;
}
template <Port port, uint8_t index, Direction direction>
Pin<port, index, direction>::operator State(void)
{
	return is_high() ? State::HIGH : State::LOW;
}

template <Port port, uint8_t index, Direction direction>
void Pin<port, index, direction>::set(void)
{
	switch (port)
	{
		case Port::B: PORTB |= (1 << index); break;
		case Port::C: PORTC |= (1 << index); break;
		case Port::D: PORTD |= (1 << index); break;
	}
}
template <Port port, uint8_t index, Direction direction>
void Pin<port, index, direction>::clear(void)
{
	switch (port)
	{
		case Port::B: PORTB &= ~(1 << index); break;
		case Port::C: PORTC &= ~(1 << index); break;
		case Port::D: PORTD &= ~(1 << index); break;
	}
}

template <Port port, uint8_t index, Direction direction>
void Pin<port, index, direction>::make_output(void)
{
	switch (port)
	{
		case Port::B: DDRB |= (1 << index); break;
		case Port::C: DDRC |= (1 << index); break;
		case Port::D: DDRD |= (1 << index); break;
	}
}
template <Port port, uint8_t index, Direction direction>
void Pin<port, index, direction>::make_input(void)
{
	switch (port)
	{
		case Port::B: DDRB &= ~(1 << index); break;
		case Port::C: DDRC &= ~(1 << index); break;
		case Port::D: DDRD &= ~(1 << index); break;
	}
}

template <Port port, uint8_t index, Direction direction>
bool Pin<port, index, direction>::is_high(void)
{
	switch (port)
	{
		case Port::B: return PINB & (1 << index);
		case Port::C: return PINC & (1 << index);
		case Port::D: return PIND & (1 << index);
	}
}
template <Port port, uint8_t index, Direction direction>
bool Pin<port, index, direction>::is_low(void)
{
	return !is_high();
}

template <Port port, uint8_t index, Direction direction>
bool Pin<port, index, direction>::is_output(void)
{
	switch (port)
	{
		case Port::B: return DDRB & (1 << index);
		case Port::C: return DDRC & (1 << index);
		case Port::D: return DDRD & (1 << index);
	}
}
template <Port port, uint8_t index, Direction direction>
bool Pin<port, index, direction>::is_input(void)
{
	return !is_output();
}

#endif
