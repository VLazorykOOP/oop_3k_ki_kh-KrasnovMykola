/*Ієрархія типів складається з сутностей: файл, файл для читання, файл для 
запису та файл для читання й запису.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File
{
public:
	File() : path("") {}
	File(string path) : path(path) {}
	virtual ~File() {}

	virtual void open(string path, std::ios_base::openmode mode) = 0;
	virtual void close() = 0;

	string get_path()
	{
		return path;
	}

protected:
	void set_path(string path)
	{
		this->path = path;
	}

private:
	string path;
};

class FileToRead : public virtual File
{
public:
	FileToRead() {}
	FileToRead(string path) : File(path)
	{
		if (stream.is_open())
			stream.close();
		stream.open(path);
	}
	~FileToRead() {}

	void open(string path, std::ios_base::openmode mode = ios::in)
	{
		if (stream.is_open())
			stream.close();
		set_path(path);
		stream.open(path, mode);
	}

	void close()
	{
		if (stream.is_open())
			stream.close();
	}

	template <typename T>
	T read()
	{
		T data;
		stream >> data;
		return data;
	}

private:
	ifstream stream;
};

class FileToWrite : public virtual File
{
public:
	FileToWrite() {}
	FileToWrite(string path, std::ios_base::openmode mode = ios::out) : File(path)
	{
		if (stream.is_open())
			stream.close();
		stream.open(path, mode);
	}
	~FileToWrite() {}

	void open(string path, std::ios_base::openmode mode = ios::out)
	{
		if (stream.is_open())
			stream.close();
		set_path(path);
		stream.open(path, mode);
	}

	void close()
	{
		if (stream.is_open())
			stream.close();
	}

	template <typename T>
	void write(T data)
	{
		stream << data;
	}

private:
	ofstream stream;
};

class FileToReadAndWrite : public virtual FileToRead, public virtual FileToWrite
{
public:
	FileToReadAndWrite(string path) : FileToRead(path), FileToWrite(path, ios::app)
	{
		set_path(path);
	}
	~FileToReadAndWrite() {}

	void open(string path, std::ios_base::openmode mode = ios::app | ios::in)
	{
		set_path(path);
		FileToRead::open(path);
		FileToWrite::open(path, ios::app);
	}

	void close()
	{
		FileToRead::close();
		FileToWrite::close();
	}

private:

};

int main()
{
	FileToReadAndWrite file("text.txt");
	int a, b, c;
	a = file.read<int>();
	b = file.read<int>();
	c = file.read<int>();
	
	cout << a << " " << b << " " << c << endl;

	file.write(' ');
	file.write(4);
	file.write(' ');
	file.write(5);

	file.close();
}