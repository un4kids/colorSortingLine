void setupCtlPanel()
{
  pinMode(CTL_PANEL_ENCODER_BTTN_PIN, INPUT);
  ctlPanelEncoderButton.attach(CTL_PANEL_ENCODER_BTTN_PIN);
  ctlPanelButtonA.attach(CTL_PANEL_BTTN_A_PIN);
  ctlPanelButtonB.attach(CTL_PANEL_BTTN_B_PIN);
  emergencyStopButton.attach(CTL_PANEL_BTTN_EMERGECY_STOP_PIN);
  lcd.begin(numCols, numRows);

}

void ctlPanelLoop()
{
  updateBttnsState();
  updateEncoderState();
  showDisplay();
  //  Serial.print("---------------------------->>>   ");
  //  Serial.print(renderView);
  //  Serial.print(onSubMenuItem);
  //
  //  Serial.println();

}

void updateBttnsState()
{
  ctlPanelEncoderButton.update();
  ctlPanelButtonA.update();
  ctlPanelButtonB.update();
  emergencyStopButton.update();

  updateSpeedCtl();

  if (ctlPanelEncoderButton.tapped())
  {
    Serial.println("-----------------------> TAPED");
    if (currentDisplayMode == MENU_DISPLAY_MODE)
    {
      onSubMenuItem = !onSubMenuItem;
      initSetting = !initSetting;

      renderView = true;
    }

  }
  else if (ctlPanelEncoderButton.held())
  {
    if (currentDisplayMode == MENU_DISPLAY_MODE)
    {
      currentDisplayMode = IDLE_DISPLAY_MODE;
    }
    else if (currentDisplayMode == IDLE_DISPLAY_MODE)
    {
      currentDisplayMode = MENU_DISPLAY_MODE;
    }
    renderView = true;
  }

  //check the emergency stop button state
  if (emergencyStopButton.read() == HIGH && !emergencyStopLine)
  {
    feedMech.countOfFeededObjects = 0;
    emergencyStopLine = true;
    renderView = true;
  }
  else if (emergencyStopButton.read() == LOW && emergencyStopLine)
  {
    emergencyStopLine = false;
    renderView = true;
  }
}
bool updateSpeedCtl() //add triger from remote control
{
  //  if (ctlPanelButtonA.read() == LOW)
  //  {
  //    faster = true;
  //  }
  //  faster = false;

  ctlPanelButtonA.read() == LOW ?  faster = true : faster = false;
  ctlPanelButtonB.read() == LOW ?  slower = true : slower = false;
}

void updateEncoderState()
{
  encoderNewPosition = ctlPanelEncoder.read();
  if (encoderNewPosition != encoderOldPosition && (encoderNewPosition % 4) == 0) // % 4 specific for encoder
  {
    if (encoderNewPosition > encoderOldPosition)
    {
      //  menuPointerPos++;
      if (!onSubMenuItem)
      {
        oldMenuPointerPos = menuPointerPos;
        menuPointerPos = constrain(menuPointerPos - 1, 0, menuNumItems - 1);

        if (oldMenuPointerPos != menuPointerPos)
        {
          renderView = true;
        }
      }
      else
      {
        sharedParam++;
        renderView = true;
      }
      encoderOldPosition = encoderNewPosition;
    }
    else
    {
      // menuPointerPos--;
      if (!onSubMenuItem)
      {
        oldMenuPointerPos = menuPointerPos;
        menuPointerPos = constrain(menuPointerPos + 1, 0, menuNumItems - 1);
        if (oldMenuPointerPos != menuPointerPos)
        {
          renderView = true;
        }
      }
      else
      {
        sharedParam--;
        renderView = true;
      }
      encoderOldPosition = encoderNewPosition;
    }
  }
}

void showDisplay()
{
  if (currentDisplayMode == IDLE_DISPLAY_MODE)
  {
    renderIdleMode();

  }
  else if (currentDisplayMode == MENU_DISPLAY_MODE)
  {
    renderMenuMode();
  }

}

void renderIdleMode()
{
  if (renderView)
  {
    if (emergencyStopLine)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("EMERGENCY STOP");
    } else {
      if ( !renderObjCounter)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("IDLE");
        lcd.setCursor(0, 1);
        lcd.print("objects: ");
      }
      lcd.setCursor(9, 1);
      lcd.print(feedMech.countOfFeededObjects);
      renderObjCounter = false;

    }

    renderView = false;
  }

}
void renderMenuMode()
{

  if (renderView && !onSubMenuItem)
  {
    scrolMenu(menu, menuNumItems);
  }
  else if (renderView && onSubMenuItem)
  {
    switch (menuPointerPos)
    {
      case SET_LINE_DEF_SPEED:
        renderSetDefSpeed();
        break;
      case SET_LINE_MAX_SPEED:
        renderSetMaxSpeed();
        break;
      case SET_LINE_MIN_SPEED:
        renderSetMaxSpeed();
        break;
      case SET_FEED_SPEED:
        renderSetFeedSpeed();
        break;
      case SET_COLOR_1:
        renderSetColor1();
        break;
      case SET_COLOR_2:
        renderSetColor2();
        break;
      case SET_COLOR_3:
        renderSetColor3();
        break;
    }

  }

}
void scrolMenu(String* menuItems, int menuItemsSize)
{
  menuPointerPos < numRows ? currentCursorPos = 0 : currentCursorPos = menuPointerPos;

  lcd.clear();
  if (oldMenuPointerPos > menuPointerPos || menuPointerPos == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print(">");
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print(">");
  }

  if (currentCursorPos == menuItemsSize - 1)
  {
    lcd.setCursor(1, 0);
    lcd.print(menuItems[currentCursorPos - 1]);
    lcd.setCursor(1, 1);
    lcd.print(menuItems[currentCursorPos]);
  }
  else
  {
    lcd.setCursor(1, 0);
    lcd.print(menuItems[currentCursorPos]);
    lcd.setCursor(1, 1);
    lcd.print(menuItems[currentCursorPos + 1]);
  }
  renderView = false;
}


void renderSetParam(String paramName, int val)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(paramName);
  lcd.setCursor(0, 1);
  lcd.write("value: ");
  lcd.write(String(val).c_str());

}

void renderSetDefSpeed()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetMaxSpeed()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetMinSpeed()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetFeedSpeed()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetColor1()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetColor2()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}

void renderSetColor3()
{
  if (initSetting)
  {
    sharedParam = 0;
    initSetting = false;
  }
  renderSetParam(menu[menuPointerPos], sharedParam);
  renderView = false;
}
