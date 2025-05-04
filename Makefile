# === הגדרות בסיס ===
CXX       := g++
CXXFLAGS  := -std=c++17 -Wall -Wextra -g -I.

# כל קבצי ‎*.cpp‎ בפרויקט – מוסיף אותם אוטומטית
SRCS      := main.cpp SquareMat.cpp \
             test_scalar.cpp test_plus.cpp test_onari.cpp \
             test_doubleplus.cpp test_divide.cpp

OBJS      := $(SRCS:.cpp=.o)
TARGET    := Main          # שם קובץ‑ההרצה שיווצר

# === מטרות עיקריות ===
.PHONY: all Main test valgrind clean

all: $(TARGET)            # make (ללא ארגומנט) – קומפילציה בלבד

# בניית קובץ ההרצה
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# make Main – קומפילציה (אם צריך) + הרצה
Main: $(TARGET)
	@echo ">>> Running ./$(TARGET) ..."
	@./$(TARGET)

# make test – זהה ל‑Main (אפשר לשנות להדפסת הודעה אחרת אם תרצה)
test: Main

# בדיקת זליגות זיכרון
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# קומפילציית כל ‎.cpp‎ לאובייקט תואם
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ניקוי קבצים זמניים וקובץ ההרצה
clean:
	rm -f $(OBJS) $(TARGET)
