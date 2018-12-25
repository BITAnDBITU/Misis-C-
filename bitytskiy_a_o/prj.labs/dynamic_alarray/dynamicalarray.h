#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
class DynamicalArray {
public:
	DynamicalArray();
	~DynamicalArray();
	DynamicalArray(const int size);
	DynamicalArray(const DynamicalArray& obj);

	bool operator ==(const DynamicalArray& obj) const {

		if (size_ == obj.size_) {
			for (int i = 0; i < size_; i++)
			{
				if (data_[i] != obj.data_[i]) {
					return false;
				}
			}
		}
	}
	bool operator!=(const DynamicalArray& obj) const {
		return !operator==(obj);
	}

	int getSize();
	void setSize(int size);
	int& operator[](const int ind) const;
	DynamicalArray& operator=( const DynamicalArray& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
private:
	int size_{ 0 };

	int* data_{ nullptr };
};
#endif;
