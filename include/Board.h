#pragma once

#include <string>
#include <list>
#include <memory>
#include "Stick.h"
#include "States.h"

class Board {
public:
	Board();

private:
	std::list<std::shared_ptr<Stick>> m_sticks;
	States m_states;

};