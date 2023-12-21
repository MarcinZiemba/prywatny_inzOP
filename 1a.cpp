#include <iostream>
#include <string>

// Product class
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}
	void setMemory(const std::string& memory) {
		memory_ = memory;
	}
	void setStorage(const std::string& storage) {
		storage_ = storage;
	}
	void setGPU(const std::string& gpu) {
		gpu_ = gpu;
	}
	void display() {
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: " << memory_ << std::endl;
		std::cout << "Storage: " << storage_ << std::endl;
		std::cout << "GPU: " << storage_ << std::endl;
	}
private:
	std::string cpu_;
	std::string memory_;
	std::string storage_;
	std::string gpu_;
};
// Builder interface
class ComputerBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	virtual void buildGPU(const std::string& storage) = 0;
	virtual Computer getResult() = 0;
};
// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
	DesktopComputerBuilder() {
		computer_ = Computer();
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
	void buildGPU(const std::string& gpu) override {
		computer_.setGPU(gpu);
	}
	Computer getResult() override {
		return computer_;
	}
private:
	Computer computer_;
};
// Director
class ComputerAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		builder.buildStorage("rtx 1060");
		return builder.getResult();
	}
};

class newComputerCassembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i9");
		builder.buildMemory("32GB");
		builder.buildStorage("1TB SSD");
		builder.buildStorage("rtx 3060");
		return builder.getResult();
	}
};

using namespace std;

int main() {
	DesktopComputerBuilder desktopBuilder;
	ComputerAssembler assembler;
	Computer desktop = assembler.assembleComputer(desktopBuilder);
	std::cout << "Desktop Computer Configuration:" << std::endl;
	desktop.display();

	cout << "Drugi komputer" << endl;
	DesktopComputerBuilder newDesktopBuilder;
	newComputerCassembler newAssembler;
	Computer newDesktop = newAssembler.assembleComputer(newDesktopBuilder);
	newDesktop.display();

	return 0;
}
