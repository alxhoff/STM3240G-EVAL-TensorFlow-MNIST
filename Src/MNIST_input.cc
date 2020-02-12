
#include "main.h"

#define INPUT_IMAGE_SIZE 28
#define INPUT_BOX_THICKNESS 2
#define INPUT_IMAGE_SIZE_PIXEL                                                 \
	((int)((double)BSP_LCD_GetYSize() / INPUT_IMAGE_SIZE) *                \
	 INPUT_IMAGE_SIZE)
#define INPUT_BOX_TOP_MARGIN                                                   \
	((BSP_LCD_GetYSize() - INPUT_IMAGE_SIZE_PIXEL -                        \
	  2 * INPUT_BOX_THICKNESS) /                                           \
	 2)
#define INPUT_BOX_SIDE_MARGIN INPUT_BOX_TOP_MARGIN
#define INPUT_BOX_X_OUTER INPUT_BOX_SIDE_MARGIN
#define INPUT_BOX_X_INNER INPUT_BOX_SIDE_MARGIN + INPUT_BOX_THICKNESS
#define INPUT_BOX_Y_OUTER INPUT_BOX_SIDE_MARGIN
#define INPUT_BOX_Y_INNER INPUT_BOX_SIDE_MARGIN + INPUT_BOX_THICKNESS
#define RUN_BOX_WIDTH                                                          \
	(BSP_LCD_GetXSize() - INPUT_IMAGE_SIZE_PIXEL -                         \
	 3 * INPUT_BOX_TOP_MARGIN - 2 * INPUT_BOX_THICKNESS)
#define RUN_BOX_X                                                              \
	(INPUT_BOX_SIDE_MARGIN * 2 + INPUT_BOX_THICKNESS * 2 +                 \
	 INPUT_IMAGE_SIZE_PIXEL)
#define RUN_BOX_HEIGHT 40
#define RUN_BOX_Y (BSP_LCD_GetYSize() / 2 - (RUN_BOX_HEIGHT / 2))

static uint32_t x = 0, y = 0;
static TS_StateTypeDef TS_State;
static uint8_t TSInputImage[INPUT_IMAGE_SIZE][INPUT_IMAGE_SIZE] = {0};

static void SaveInputImage(void){
    volatile static uint16_t tmp = 0;
    for(int y = INPUT_BOX_Y_INNER; y < (INPUT_BOX_Y_INNER + INPUT_IMAGE_SIZE_PIXEL); y++){
        for(int x = INPUT_BOX_X_INNER; x < (INPUT_BOX_X_INNER + INPUT_IMAGE_SIZE_PIXEL); x++){
            tmp = BSP_LCD_ReadPixel(x, y);
        }
    }
}

uint8_t RunButtonPressed(uint32_t x, uint32_t y)
{
    if(
        (x >= RUN_BOX_X) && (x <= (RUN_BOX_X + RUN_BOX_WIDTH)) &&
        (y >= RUN_BOX_Y) && (y <= (RUN_BOX_Y + RUN_BOX_HEIGHT))
            )
        return 1;

    return 0;
}

uint8_t DrawInBox(uint32_t x, uint32_t y, uint32_t dot_radius)
{
	if ((x < (INPUT_BOX_X_INNER + dot_radius)) ||
	    (x > (INPUT_BOX_X_INNER + INPUT_IMAGE_SIZE_PIXEL - dot_radius))) {
		return 0;
	}
	if ((y < (INPUT_BOX_Y_INNER + dot_radius)) ||
	    (y > (INPUT_BOX_Y_INNER + INPUT_IMAGE_SIZE_PIXEL - dot_radius))) {
		return 0;
	}

	return 1;
}

void DrawTouchInput(void)
{
	static const uint32_t dot_radius = 5;

	BSP_TS_GetState(&TS_State);

	if (TS_State.TouchDetected) {
		x = TS_State.x;
		y = TS_State.y;

		if (DrawInBox(x, y, dot_radius)){
            printf("Drawing in box\n");
			BSP_LCD_FillCircle(x, y, dot_radius);
        }
        else if(RunButtonPressed(x, y)){
            printf("Save image\n");
            SaveInputImage();
        }
	}
}

void DrawInputScreen(void)
{
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(INPUT_BOX_X_OUTER, INPUT_BOX_Y_OUTER,
			 INPUT_IMAGE_SIZE_PIXEL + 2 * INPUT_BOX_THICKNESS,
			 INPUT_IMAGE_SIZE_PIXEL + 2 * INPUT_BOX_THICKNESS);
	BSP_LCD_FillRect(RUN_BOX_X, RUN_BOX_Y, RUN_BOX_WIDTH, RUN_BOX_HEIGHT);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(INPUT_BOX_X_INNER, INPUT_BOX_Y_INNER,
			 INPUT_IMAGE_SIZE_PIXEL, INPUT_IMAGE_SIZE_PIXEL);
	BSP_LCD_FillRect(RUN_BOX_X + INPUT_BOX_THICKNESS,
			 RUN_BOX_Y + INPUT_BOX_THICKNESS,
			 RUN_BOX_WIDTH - 2 * INPUT_BOX_THICKNESS,
			 RUN_BOX_HEIGHT - 2 * INPUT_BOX_THICKNESS);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(RUN_BOX_X + 20, RUN_BOX_Y + 12,
				(uint8_t *)"RUN", LEFT_MODE);
}
