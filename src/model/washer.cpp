#include "washer.hpp"
#include "washer_body.hpp"
#include "drum.hpp"



// ==================== FUNCTIONS ====================

void drawWasher() {
	drawWasherFrontWall(1, -1, 1, 1, 1, 1, -1, 1, 1, -1, -1, 1);
	drawWasherRightWall(1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1);
	drawWasherLeftWall(-1, -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1);
	drawWasherBottomWall(1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1);
	drawWasherTopWall(1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1);
	drawWasherBackWall(-1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1);

	drawDrum();
}