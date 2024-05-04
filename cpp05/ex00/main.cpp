#include "Bureaucrat.hpp"

int	main(void)
{
	{
		std::cout << "\n============ Zarniwoop's life ============" << std::endl;
		try {
			Bureaucrat	Bcrat1("Zarniwoop", 1);
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Decrement grade " << std::endl;
			Bcrat1.decrementGrade();
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Decrement grade " << std::endl;
			Bcrat1.decrementGrade();
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Increment grade" << std::endl;
			Bcrat1.incrementGrade();
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Increment grade" << std::endl;
			Bcrat1.incrementGrade();
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Increment grade" << std::endl;
			Bcrat1.incrementGrade();
			std::cout << Bcrat1 << std::endl;

			std::cout << Bcrat1.getName() << " -> Increment grade" << std::endl;
			Bcrat1.incrementGrade();
			std::cout << Bcrat1 << std::endl;
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n=============== Hoopz's life =============" << std::endl;
		try {
			Bureaucrat	Bcrat2("Hoopz", 150);
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Increment grade" << std::endl;
			Bcrat2.incrementGrade();
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Increment grade" << std::endl;
			Bcrat2.incrementGrade();
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Decrement grade " << std::endl;
			Bcrat2.decrementGrade();
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Decrement grade " << std::endl;
			Bcrat2.decrementGrade();
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Decrement grade " << std::endl;
			Bcrat2.decrementGrade();
			std::cout << Bcrat2 << std::endl;

			std::cout << Bcrat2.getName() << " -> Increment grade" << std::endl;
			Bcrat2.incrementGrade();
			std::cout << Bcrat2 << std::endl;
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n============= Nameless's life ============" << std::endl;
		try {
			Bureaucrat	Bcrat3;
			std::cout << Bcrat3 << std::endl;

			for (int i = 0; i < 150; i++)
			{
				std::cout << Bcrat3.getName() << " -> Increment grade" << std::endl;
				Bcrat3.incrementGrade();
				std::cout << Bcrat3 << std::endl;
			}
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	return (0);
}
