#include "Span.hpp"

Span::Span(unsigned int size)
{
	this->index = 0;
	this->size = size;
	this->array = new int[size];
}

Span::Span(const Span &ref)
{
	*this = static_cast<Span>(ref);
}

Span::~Span()
{
	delete [] this->array;
}

Span		&Span::operator=(Span const &ref)
{
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}


void Span::addNumber(int num){
	if (this->index == this->size)
		throw Span::IsFull();
	this->array[this->index] = num;
	this->index++;
}

int Span::getHigh(){
	int high = this->array[0];
    for(unsigned int i = 0; i < this->size; i++){
        if(this->array[i] > high){
            high = this->array[i];
        }
    }
	return (high);
}

int Span::longestSpan(){
	return (Span::getHigh() - Span::getLow());
}

int Span::getLow(){
	int min = this->array[0];
    for(unsigned int i = 0; i < this->size; i++){
        if(this->array[i] < min){
            min = this->array[i];
        }
    }
	return (min);
}

int Span::getSecondLow(){
	int holder = Span::getLow();
	int min = Span::getHigh();
    for(unsigned int i = 0; i < this->size; i++){
        if(this->array[i] < min && this->array[i] > holder){
            min = this->array[i];
        }
    }
	return (min);
}

int Span::shortestSpan(){
	return (Span::getSecondLow() -Span::getLow());
}
