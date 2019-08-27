#include "gpl/events/primitive/mouse_over.h"

namespace Gpl
{
	namespace Event
	{
		namespace Primitive
		{
			MouseOver::MouseOver(void)
			{
			}
			MouseOver::~MouseOver(void)
			{
			}

			void MouseOver::copy(const MouseOver& other)
			{
				Event::Primitive::Base::copy(other);
			}
			void MouseOver::move(MouseOver&& other)
			{
				Event::Primitive::Base::move(std::move(other));
			}
		}
	}
}
