#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mut;
std::condition_variable cond_var;
int flag = 0;


//std::

struct Igor{
	void write(int i){
		std::cout << "Igor " << i << std::endl;
	}

};

void task1(void){
	while (1){
		std::unique_lock<std::mutex> lock(mut);
		cond_var.wait(lock, []{
			return ((flag & 0x3) == 0);
		});
		std::cout << 1;
		++flag;
		cond_var.notify_all();
	}
}

void task2(void){
	while (1){
		std::unique_lock<std::mutex> lock(mut);
		cond_var.wait(lock, []{
			return ((flag & 0x3) == 1);
		});
		std::cout << 2;
		++flag;
		cond_var.notify_all();
	}

}

void task3(void){
	while (1){
		std::unique_lock<std::mutex> lock(mut);
		cond_var.wait(lock, []{
			return ((flag & 0x3) == 2);
		});
		std::cout << 3;
		++flag;
		cond_var.notify_all();
	}

}

void task4(void){
	while (1){
		std::unique_lock<std::mutex> lock(mut);
		cond_var.wait(lock, []{
			return ((flag & 0x3) == 3);
		});
		std::cout << 4;
		++flag;
		cond_var.notify_all();
	}

}

void hello(void){
	std::cout << "hello new world" << std::endl;
	std::cout << std::thread::hardware_concurrency() << std::endl;
	std::cout << std::this_thread::get_id() << std::endl;



}

int main(int argc, char** argv){

	std::thread thread1(task1);
	std::thread thread2(task2);
	std::thread thread3(task3);
	std::thread thread4(task4);


//	thread1.join();

//	std::cout << 4 << std::endl;

/*
	std::thread thr1([]{
		hello();
	});
	thr1.join();
	Igor igoryan;

	auto op = std::bind(&Igor::write, igoryan, 900);

	op(igoryan);
	std::cout << thr1.get_id() << std::endl;

*/
	int n;
	std::cin >> n;
//	

//	std::cout << "hello world";
	return 0;
}