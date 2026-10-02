# Exercises: RTOS ISR API

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing Parameter
A developer writes the following ISR for a button press:
```c
void Button_ISR() {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(button_sem, &xHigherPriorityTaskWoken);
    
    // The developer forgets to call portYIELD_FROM_ISR()!
    BUTTON_FLAG = 0; // Clear hardware interrupt
}
```
`Task_UI` is waiting for `button_sem` and has Priority 5.
`Task_Background` is currently running and has Priority 2.
**Task:** Describe exactly what happens when the button is pressed. When will `Task_UI` actually process the button press, and how much latency will be introduced?

## Exercise 2: Why two APIs?
**Task:** If the `...FromISR` APIs are non-blocking and safe, why doesn't FreeRTOS just throw away the standard APIs and force developers to use the `...FromISR` versions everywhere (even inside Tasks) to simplify the codebase?
