#include <iostream>
#include <stdint.h>


typedef struct Datapp
{
	int value;
} Data;


uintptr_t serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data *data = new Data;

	data->value = 10;
	uintptr_t ptr = serialize(data);

	data = deserialize(ptr);

	std::cout << data->value << std::endl;
	return 0;
}
