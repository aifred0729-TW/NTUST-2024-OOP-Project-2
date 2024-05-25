#include "../../Includes/Gadget/Dice.h"

// Public

Dice::Dice() {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = 0;
	this->result.resize(this->amount, false);
	this->successRate.resize(this->amount, 0);
	this->rateAddition.resize(this->amount, 0);
}

Dice::Dice(uint8_t amount, uint8_t successRate) {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = amount;
	this->result.resize(this->amount, false);
	this->successRate.resize(this->amount, successRate);
	this->rateAddition.resize(this->amount, 0);
}

Dice::Dice(std::vector<uint8_t> successRate) {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = successRate.size();
	this->result.resize(this->amount, false);
	this->successRate.resize(this->amount, 0);
	for (int i = 0; i < this->amount; i++)
		this->successRate[i] = std::min<uint8_t>(90, successRate[i]); // successRate := Stat::Speed / 100, but not exceed 90.
	this->rateAddition.resize(this->amount, 0);
}


Dice::Dice(uint8_t speed) {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = static_cast<uint8_t>(speed / 10); // MaxMovementPoint := Stat::Speed / 10
	this->result.resize(this->amount, false);
	this->rateAddition.resize(this->amount, 0);
	this->successRate.resize(this->amount, std::min<uint8_t>(90, speed)); // successRate := Stat::Speed / 100, but not exceed 90.
}

void Dice::RollDice(void) {
	// Random Engine
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 99);
	this->movementPoint = 0;

	// Roll Dice
	this->result.resize(this->amount, false);
	this->rateAddition.resize(this->amount, 0);
	this->successRate.resize(this->amount, 0);
	for (int i = 0; i < this->amount; i++) {
		this->result[i] = (dis(gen) < this->successRate[i] + this->rateAddition[i]) || (i < focusCount);
		if (this->result[i]) {
			this->movementPoint++;
		}
	}

	// Reset FocusCount and RateAddition
	this->focusCount = 0;
}

void Dice::resize(uint8_t amount) {
	this->amount = amount;
	this->result.resize(amount, false);
	this->successRate.size() == 0 ? this->successRate.resize(amount, 0) : this->successRate.resize(amount, this->successRate[0]);
	this->rateAddition.size() == 0 ? this->rateAddition.resize(amount, 0) : this->rateAddition.resize(amount, this->rateAddition[0]);
}

void Dice::displayResult(void) {
	std::cout << "ÂY»ëµ²ªG: " << (unsigned)movementPoint << " / " << (unsigned)amount << std::endl;
}

void Dice::setMovementPoint(const uint8_t movementPoint) {
	this->movementPoint = movementPoint;
}

void Dice::SetAmount(const uint8_t amount) {
	this->amount = amount;
}

void Dice::SetFocusCount(const uint8_t focusCount) {
	if (focusCount > this->amount)
		return;

	this->focusCount = focusCount;
}

void Dice::SetSuccessRate(const std::vector<uint8_t>& successRate) {
	this->successRate = successRate;
}

void Dice::SetRateAddition(const std::vector<double>& rateAddition) {
	this->rateAddition = rateAddition;
}

void Dice::SetResult(const std::vector<bool>& result) {
	this->result = result;
}

uint8_t Dice::GetMovementPoint(void) {
	return this->movementPoint;
}

uint8_t Dice::GetAmount(void) {
	return this->amount;
}

uint8_t Dice::GetFocusCount(void) {
	return this->focusCount;
}

std::vector<uint8_t> Dice::GetSuccessRate(void) {
	return this->successRate;
}

std::vector<double> Dice::GetRateAddition(void) {
	return this->rateAddition;
}

std::vector<bool> Dice::GetResult(void) {
	return this->result;
}