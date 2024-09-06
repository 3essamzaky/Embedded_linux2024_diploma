/******** threads & FileSystem ****************

=================== some notes ==================

1- join(): is used to wait for a thread to finish its execution
example:
  void run() {
    for(int i = 0; i <10; i++) {
        std::cout << "hello form fun" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
int main() {
    std::thread t1(run);
    std::cout << "hello form main" << std::endl; 
    t1.join();      //the thread will execute here until it is finished
    std::cout << "hello form after main" << std::endl; 

}
- Double join will result into program termination to prevent that check if t.jionable() == true => make it t.join()


2- detach(): is used when you want the thread to run in the background without needing to wait for it.
example:
  void run() {
    for(int i = 0; i <10; i++) {
        std::cout << "hello form fun" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
int main() {
    std::thread t1(run);
    std::cout << "hello form main" << std::endl; 
    t1.detach();      //the main thread will execute and dont care if the thread is finished or not
    std::cout << "hello form after main" << std::endl; 

}

3- this_thread::get_id(): returns the id of the current thread

4- std::this_thread::sleep_for(): is used to pause the execution of a thread for the specified amount of time.

5- std::this_thread::sleep_until(): is used to pause the execution of a thread until the specified time. (alarm)

6- race condition: is when two threads access the same memory location at the same time. and you can solve it by using mutexes

7- when you use mutexes, you need to use std::lock_guard<std::mutex> lock(m); to lock the mutex and unlock it when you are done using it.

8- use unique_lock<std::mutex> lock(m); to lock the mutex and unlock it when you are done using it. // when you lock and unlock at any time

9 - try_lock() tries to lcock the mutex and returns true if it was successful, false otherwise.
example:
  int count = 0;
  std::mutex m;
  void run() {
    for(int i = 0; i <10; i++) {
        std::cout << "hello form fun" << std::endl;
        if(m.try_lock()) {   //depond on the CPU
            count++;
            m.unlock();
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

10 - to see threads => ps -auxH | grep <name of execuatable> ex: ps -auxH | grep a.out
=================== notes on codes ===================

Ex. thread_sleep & thread_sleep_until:
#define     TIME         5
void fun(){
    
    int count =0;
    while(count < 1000){
        std::cout << "hello form fun" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count ++;
    
    }
}
int main() {
  
  std::cout <<"sleeeping for 2 seconds" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));

  std::chrono::system_clock::time_point
  WakeupTime = std::chrono::system_clock::now()+std::chrono::seconds(TIME);
  std::cout << "sleeping until " << TIME << std::endl;

  std::this_thread::sleep_until(WakeupTime); std::cout << "wake up" << std::endl;
  
  
  return 0;
}
---------------------------------------------------

Ex. about race condition:

int count = 0;
void fun() {
    for(int i = 0; i < 10000; i++) {
            count++;
    }
int main() {
    std::thread t1(fun);
    std::thread t2(fun);
    t1.join();
    t2.join();
    std::cout << count << std::endl; // Output: 19477 ,19999, 20000  this is because of race condition
    return 0;
}
----------------------------------------------------


Ex to solve race condition:

int count = 0;
std::mutex m;
void fun() {
    for(int i = 0; i < 10000; i++) {
            m.lock();     //use std::lock_guard<std::mutex> lock(m); //according to RAII
            count++;
            m.unlock();
    }
int main() {
    std::thread t1(fun);
    std::thread t2(fun);
    t1.join();
    t2.join();
    std::cout << count << std::endl; // Output: 20000
    return 0;
}
------------------------------------------------------

Ex using unique_lock<std::mutex> lock(m):

int count = 0;
std::mutex m;
void fun() {
    for(int i = 0; i < 10000; i++) {
            std::unique_lock<std::mutex> lock(m);
            count++;
            lock.unlock();
            cont+2;
            lock.lock();
    }
int main() {
    std::thread t1(fun);
    std::thread t2(fun);
    t1.join();
    t2.join();
    std::cout << count << std::endl; // Output: 20000
    return 0;
}
----------------------------------------------------------------

Ex. using promise & future:

int sum(int a, int b) {
  return a + b;
}

int main() {
  // Create a promise and future object 
  // set the value using the promise
  // get the value using the future

  std::promise<int> PromiseObj;
  std::future<int>futureObj = PromiseObj.get_future();

  std::thread sumThread([&PromiseObj]);
  int result = sum(10, 20);

  PromiseObj.set_value(result);
  
  int value = futureObj.get();
  std::cout << value << std::endl;

  sumThread.join();
  
  return 0;
} 
----------------------------------------------------------------

Ex. using packaged_task:

int sum(int a, int b) {
  return a + b;
}

int main() {
  std::packaged_task<int(int, int)> task(sum);
  std::future<int> result = task.get_future();
  std::thread t(std::move(task), 1, 2);
  t.join();
  std::cout << "result: " << result.get() << std::endl;
  return 0;
}
----------------------------------------------------------------

Ex. using async:

int sum(int a, int b) {
  return a + b;
}

int main() {
  //start a task asyncronously
  std::future<int >futureResult = std::async(std::launch::async,sum, 2, 3);
  std::this_thread::sleep_for(std::chrono::seconds(5));

  //Get the result when nedded
  int result = futureResult.get();
  std::cout << result << std::endl;  
  
  return 0;
}

-----------------------------------------------------------------
Ex. defer_lock:

std::mutex mtx;
void threadFunction() {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);  // Mutex not locked yet
    // Perform some non-critical work here
    lock.lock();  // Manually lock the mutex
    // Critical section
    std::cout << "Thread is executing with more control\n";
    lock.unlock();  // Manually unlock the mutex
    // Mutex automatically unlocked again when lock goes out of scope
}

int main() {
    std::thread t(threadFunction);
    t.join();
    return 0;
}


 */