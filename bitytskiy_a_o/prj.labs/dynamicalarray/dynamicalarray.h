#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicalArray {
public:
	DynamicalArray();

	~DynamicalArray();

	DynamicalArray(const int size);

	DynamicalArray(const DynamicalArray &obj);

	bool operator==(const DynamicalArray &obj) const;

	bool operator!=(const DynamicalArray &obj) const;

	int getSize();

	void setSize(int size);

	int &operator[](const int ind) const;

	DynamicalArray &operator=(const DynamicalArray &rhs);

	std::ostream &writeTo(std::ostream &ostrm) const;

private:
	int size_{ 0 };

	int *data_{ nullptr };
};

#endif;
