#---------------------------------------------------------------------------
# Copyright 2010, 2011 Sushil J. Louis and Christopher E. Miles, 
# Evolutionary Computing Systems Laboratory, Department of Computer Science 
# and Engineering, University of Nevada, Reno. 
#
# This file is part of OpenECSLENT 
#
#    OpenECSLENT is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    OpenECSLENT is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with OpenECSLENT.  If not, see <http://www.gnu.org/licenses/>.
#---------------------------------------------------------------------------
#-------------------------End Copyright Notice------------------------------

import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS

from vector import Vector2, point2
from inputMgr import MouseEvent, MouseButton

class UIDefaults:
    POS = (0, 0)
    WIDTH = 100
    HEIGHT = 20

    PANEL_SIZE = (100, 20)
    PANEL_MATERIAL = "ECSLENT/navy/material/shipInfo/overlay"
    LINE_SEP_MATERIAL  = "ECSLENT/line"

    LABEL_SIZE = (100, 20)
    LABEL_X_OFFSET = 5
    LABEL_Y_OFFSET = 5
    LABEL_TEXT_COLOR = (1.0, 1.0, 0.7)

    BUTTON_SIZE = (50, 20)
    BUTTON_OFF_TEXT_COLOR = (1.0, 1.0, 0.0)
    BUTTON_ON_TEXT_COLOR  = (0.0, 0.0, 0.5)

    MENU_ITEM_SIZE = (100, 20)
    MENU_DEFAULT_TEXT_COLOR = (1.0, 1.0, 0.0)
    MENU_SELECTED_TEXT_COLOR = (0.0, 0.0, 0.5)
    MENU_MATERIAL = "ECSLENT/navy/material/rmenu"

class Widget():
    """Top level UI object
    """
    def __init__(self, engine, parent = None, pos=None, size=None):
        if pos is None: #if we default parameter these all objects will share a common instantiation which WILL cause nightmares
            pos = point2(0,0)
        if size is None: #if we default parameter these all objects will share a common instantiation which WILL cause nightmares
            size = point2(100,13)

        assert engine is not None
        if type(pos) is tuple:
            pos = point2(*pos)
        if type(size) is tuple:
            size = point2(*size)

        self._pos = pos
        self._size = size
        self.engine = engine
        self.parent = parent

    @property
    def pos(self):
        return self._pos
    @pos.setter
    def pos(self, value):
        self._pos = value
        self.posChanged()
    def posChanged(self):
        pass

    @property
    def size(self):
        return self._size
    @size.setter
    def size(self, value):
        self._size = value
        self.sizeChanged()
    def sizeChanged(self):
        pass

    @property
    def width(self):
        return self._size.x
    @width.setter
    def width(self, val):
        self.size = point2(val, self.size.y)

    @property
    def height(self):
        return self._size.y
    @height.setter
    def height(self, val):
        self.size = point2(self.size.x, val)
           

    @property
    def screenPos(self):
        if self.parent:
            return self.parent.screenPos + self.pos
        else:
            return self.pos

    def cursorInMe(self, mx, my):
        ax, ay = (self.screenPos.x, self.screenPos.y)
        return ((mx >= ax) and (mx <= ax + self.width) and (my >= ay) and (my <= ay + self.height))



class UIOverlay(Widget):
    """
    All UI elements live within this overlay.
    """
    def __init__(self, engine):
        Widget.__init__(self, engine)
        self.overlayManager = ogre.OverlayManager.getSingleton()
        self.pid         = "UIPanel" + str(engine.widgetMgr.getNextId())
        self.panel       = self.overlayManager.createOverlayElement("Panel", self.pid)
        self.panel.setMetricsMode(ogre.GMM_PIXELS)#RELATIVE_ASPECT_ADJUSTED)
        self.panel.setPosition(0, 0)
        width  = self.engine.gfxSystem.renderWindow.getWidth()
        height = self.engine.gfxSystem.renderWindow.getHeight() # VERY IMPORTANT or rayscene queries fail
        self.panel.setDimensions(width, height)        
        self.panel.setMaterialName("ECSLENT/UI")
        self.panel.show()

        self.id = "MainUI"
        self.overlayName = "UIOverlay" + str(engine.widgetMgr.getNextId())
        self.overlay     = self.overlayManager.create(self.overlayName)
        self.overlay.add2D(self.panel)
        self.overlay.show()
        self.panel.show()

    def show(self):
        self.overlay.show()
        self.panel.show()

    def hide(self):
        self.panel.hide()
        self.overlay.hide()

    def render(self):
        pass

    def tick(self, dtime):
        pass
        
        
class Panel(Widget):
    """
    """
    class Placement:
        Below = 0
        Right = 1

    def __init__(self, engine, parent = None, name = "ex.Panel", pos = (0.0, 0.0), size = UIDefaults.PANEL_SIZE, material = None):
        Widget.__init__(self, engine, parent = parent, pos = pos, size = size)
        self.overlayManager = ogre.OverlayManager.getSingleton()

        self.pid         = name + str(engine.widgetMgr.getNextId())
        self.panel       = self.overlayManager.createOverlayElement("Panel", self.pid)
        self.panel.setMetricsMode(ogre.GMM_PIXELS)#RELATIVE_ASPECT_ADJUSTED)
        self.panel.setPosition(self.pos.x, self.pos.y)
        #self.panel.setDimensions(self.width, self.height)
        self.height = 0 # otherwise, the panel has extra height when using as a parent for labels and other widgets.
        self.panel.setDimensions(self.width, self.height)
        if material:
            self.panel.setMaterialName(material)

        self.panel.show()        

        if not self.parent:
            self.id = name
            self.overlayName = name + str(engine.widgetMgr.getNextId())
            self.overlay     = self.overlayManager.create(self.overlayName)
            self.overlay.add2D(self.panel)
            self.overlay.show()
            #print "---------> Created overlay and added panel to overlay: ",  self.overlayName

        self.panel.show()

        self.belowPos = point2(0,0)
        self.rightPos = point2(0,0)
        self.xgap = 0
        self.ygap = 0
        self._items = []

        self.lheight = 1
        self._linePanels = [] # used by menu items
        self.addSep(0)
        pass

    def linePanel(self):
        lid = self.pid + "line/" + str(self.engine.widgetMgr.getNextId())
        lp = self.overlayManager.createOverlayElement("Panel", lid)
        lp.setMetricsMode(ogre.GMM_PIXELS)#RELATIVE_ASPECT_ADJUSTED)
        lp.setPosition(0, 0)
        lp.setDimensions(self.width, self.lheight)
        lp.setMaterialName("ECSLENT/line")
        lp.show()
        return lp
 
    def addSep(self, y):
        lp = self.linePanel()
        self._linePanels.append(lp)
        lp.setPosition(0, y) # lineSep, 0, 0
        self.panel.addChild(lp)

    def adjustSeps(self):
        '''
        QUEST: What is this? - cmiles
        '''
        for lp in self._linePanels:
            lp.setDimensions(self.width, self.lheight)

    def render(self):
        for item in self._items:
            item.render()

    def show(self):
        if not self.parent:
            self.overlay.show()
        self.panel.show()
        for item in self._items:
            item.show()

    def hide(self):
        for item in self._items:
            item.hide()
        self.panel.hide()
        if not self.parent:
            self.overlay.hide()

    def posChanged(self):
        self.panel.setPosition(self.pos.x, self.pos.y)
        for item in self._items:
            item.posChanged()

    def addItem(self, item, func = None, placement = Placement.Below):
        self._items.append(item)
        if(self.width < item.width):
            self.width = item.width
            self.adjustSeps()

        #pdb.set_trace()
        if placement == Panel.Placement.Below:
            item.pos = self.belowPos
            self.rightPos = self.belowPos + point2(item.width + self.xgap, 0)
            self.belowPos = point2(0, self.belowPos.y + item.height + self.ygap)

        elif placement == Panel.Placement.Right:
            item.pos = self.rightPos
            self.rightPos = self.rightPos + point2(item.width + self.xgap, 0)

        if self.rightPos.x > self.width:
            self.width = self.rightPos.x

        if self.belowPos.y > self.height:
            self.height = self.belowPos.y
        #self.height += item.height

        #print 'Panel.addItem', self, item, placement, item.pos, self.belowPos, self.rightPos

        self.panel.addChild(item.getOverlayElementToAdd())

        self.panel.setDimensions(self.width, self.height)
        self.addSep(self.height)

    def deleteItem(self, item):
        item.hide()
        self._item.remove(element)

    def getItems(self):
        return self._items

    def getOverlayElementToAdd(self):
        return self.panel


class Label(Widget):
    '''
    '''
    def __init__(self, engine, parent = None, caption = "Ex.Label", color = (1.0, 1.0, 0.7), size = UIDefaults.LABEL_SIZE, pos = (0, 0)):
        '''
        '''
        Widget.__init__(self, engine, parent = parent, pos = pos, size = size)
        self.overlayManager =  ogre.OverlayManager.getSingleton()
        self.caption = caption
        self.color   = color

        self.xOffset = 5
        self.yOffset = 2

        self.id = "ECSLENT/Label/" + str(self) + "/" + caption  + "/" + str(engine.widgetMgr.getNextId())
        self.textArea = self.overlayManager.createOverlayElement("TextArea", self.id)
        self.textArea.setMetricsMode(ogre.GMM_PIXELS)
        self.textArea.setCaption(caption)
        self.textArea.setPosition(self.pos.x  + self.xOffset, self.pos.y + self.yOffset)
        self.textArea.setDimensions(self.width, self.height)
        self.textArea.setFontName("BlueHighway")
        self.textArea.setCharHeight(self.height)
        self.textArea.setColour(self.color)
        self.textArea.show()

        #textArea.setColourTop((1.0, 1.0, 0.7))
        #textArea.setColourBottom((1.0, 1.0, 0.7))

    def render(self):
        pass

    def tick(self, dtime):
        pass
#-------------------------------------------------------------------
    def getTextArea(self):
        return self.textArea
#-------------------------------------------------------------------
    def getOverlayElementToAdd(self):
        return self.textArea
#-------------------------------------------------------------------
    def show(self):
        self.textArea.show()
#-------------------------------------------------------------------
    def hide(self):
        self.textArea.hide()
#-------------------------------------------------------------------
    def setCaption(self, caption):
        self.caption = caption
        self.textArea.setCaption(self.caption)
#-------------------------------------------------------------------
    def getCaption(self):
        return self.caption

    def posChanged(self):
        #print 'Label.posChanged', self.pos, self.screenPos
        self.textArea.setPosition(self.pos.x + self.xOffset, self.pos.y + self.yOffset)

    def sizeChanged(self):
        #print 'Label.sizeChanged', self.size
        self.textArea.setDimensions(self.width, self.height)

    def setCharHeight(self, height):
        self.height = height
        self.setCharHeight(height)

#-----------------------------------------------------------------------------------------------------------------
class MenuItem(Panel):
    '''A panel and a label
    '''

    def __init__(self, engine, parent = None, name = "ex.MenuItem", pos = (0, 0), size = (100, 15), func = None, material="ECSLENT/navy/material/rmenu"):
        Panel.__init__(self, engine, parent = parent, name = name+"Panel", pos = pos, size = size, material = material)
        self.label = Label(engine, parent = None, caption = name, pos = (0, 0), size = size)
        self.height = 15
        self.label.show()
        self.panel.addChild(self.label.textArea)
        self.name = name
        self.func = func
        self.isSelected = False

        self._subMenu = Panel(engine, parent = self, pos = (0, 0), size = (0, 0), material = material)
        self._subMenu.pos = point2(self.width + self.xgap, 0)
        self.panel.addChild(self._subMenu.panel)
        self._subMenu.hide()

        self.registerEventHandlers()
        self.isActive = False

    def addItem(self, mi):
        self._subMenu.addItem(mi)

    def clearSelection(self):
        self.isSelected = False;
        for it in self._subMenu._items:
            it.clearSelection()

    def tick(self, dtime):
        pass

    def hideAllOther(self, mi):
        for item in self._subMenu._items:
            if mi != item:
                item.isSelected = False
                item._subMenu.hide()

    def render(self):
        ms = self.engine.inputMgr.ms

        if self.isActive:
            # I have a parent
            if self.inMe(): #self.cursorInMe(ms.X.abs, ms.Y.abs - self.height):
                self.isSelected = True
                self.parent.hideAllOther(self)
                self.label.textArea.setColour(UIDefaults.MENU_SELECTED_TEXT_COLOR)
                self.show()
                self._subMenu.show()
            else:
                self.label.textArea.setColour(UIDefaults.MENU_DEFAULT_TEXT_COLOR)
                self._subMenu.hide()

            for item in self._subMenu._items:
                item.render()

    def inMe(self):
        ms = self.engine.inputSystem.ms
        if isinstance(self.parent, TopMenu):
            return self.cursorInMe(ms.X.abs, ms.Y.abs - self.parent.height)
        else:
            return self.cursorInMe(ms.X.abs - self.parent.width, ms.Y.abs - self.parent.height)

    def fire(self, ms):
        if self.isLeaf() and self.isSelected: 
            #print "Firing: ", self.name
            self.func(self, ms)
 
    def isLeaf(self):
        return not self._subMenu._items

#-----------------------------------------------------------------------------------------------------------------

class NewWidget(Panel):
    '''Displays and updates framerate
    '''
    def __init__(self, engine, name = "Framerate: ", pos = (1, 1), size = (100, 13)):
        Panel.__init__(self, engine, name = name, pos = pos, size = size)
        self.label = Label(engine, caption = name, pos = (0,0), size = size)
        self.addItem(self.label)
        self.show()
        self.label.show()
        
    def tick(self, dtime):
        stats = self.engine.gfxSystem.renderWindow.getStatistics()
        self.label.setCaption("Hello")

    def render(self):
        #print "panel.show: ", self.posx, ", ", self.posy
        #self.show()
        #self.label.show()
        pass

#--------------------------------------------------------------------------------

class WidgetMgr():
    widgets = []
    idCounter = 0

    worldToWorldMenu = None
    worldToEntMenu   = None
    entToWorldMenu   = None
    entToEntMenu     = None
    entMap  = {}  # maps ent's uiname (DDG51) to entity type (boat.DDG51)

    def __init__(self, engine):
        self.x = 0


    def init(self):
        return
        self.buttonPressed = False
        screenRHS = self.engine.gfxSystem.renderWindow.getWidth()
        size = (300, 20)
        self.scenarioMap = {}

        nme = "Destroyer and Speedboat"
        self.button1 = InitMenuButton(self.engine, name = nme, pos = (300, 100), size = size, func = self.setTest1)
        self.scenarioMap[nme] = 1
        
        nme = "Five Destroyers and Destoyer"
        self.button2 = InitMenuButton(self.engine, name = nme, pos = (300, 200), size = size, func = self.setTest1)
        self.scenarioMap[nme] = 2

        nme = "Carrier and 100 speedboat swarm"
        self.button2 = InitMenuButton(self.engine, name = nme, pos = (300, 300), size = size, func = self.setTest1)
        self.scenarioMap[nme] = 6


    def setTest1(self, ms, caption):
        self.engine.testMgr.test = self.scenarioMap[caption]
        self.buttonPressed = True
        print "Clicked: ", caption

    def initEngine(self):
        """Init global UI
        """
        for etype in self.engine.entMgr.types:
            self.entMap[etype.uiname] = etype
        self.initTestMenu1()

    def crosslink(self):
        pass

    def tick(self, dtime):
        for widget in self.widgets:
            widget.tick(dtime)
        self.rightClickMenuTick(dtime)

    def render(self):
        for widget in self.widgets:
            widget.render()
        self.rightClickMenuRender()

    def initTestMenu1(self):
        """lets start with a few labels
        """

        l2 = MyNewWidget(self.engine, pos = (500, 500))
        self.widgets.append(l2)

        ui = UIOverlay(self.engine)
        self.widgets.append(ui)

        screenRHS = self.engine.gfxSystem.renderWindow.getWidth()
        screenBottom = self.engine.gfxSystem.renderWindow.getHeight()

        defaultHeight = UIDefaults.PANEL_SIZE[1]

        gameInfoWidget = GameInfoWidget(self.engine, pos = (screenRHS - 200, 0), size = (100, defaultHeight*2))
        self.widgets.append(gameInfoWidget)


        shipInfoWidget = ShipInfoWidget(self.engine, size = (100, defaultHeight*8))
        self.widgets.append(shipInfoWidget)

        commandInfoWidget = ShipCommands(self.engine)
        self.widgets.append(commandInfoWidget)

        headerWidth = 100
        width = headerWidth * 3
        mouseOverInfoWidget = ShipMouseOverInfoWidget(self.engine, pos = (screenRHS - width, screenBottom - defaultHeight*10), size = (headerWidth, defaultHeight*10))
        self.widgets.append(mouseOverInfoWidget)

        self.f1Widget = F1HelpWidget(self.engine)
        self.widgets.append(self.f1Widget)

        self.worldToWorldMenu = self.makeWorldToWorldMenu()
        #self.entToWorldMenu   = self.makeEntToWorldMenu()
        #self.worldToEntMenu   = self.makeWorldToEntMenu()
        #self.entToEntMenu     = self.makeEntToEntMenu()
        '''
        db = DebugButtonWidget(self.engine, func = printClick)
        self.widgets.append(db)
 
        #------------------------------------------------------------------
        # cursor widget

        cursor = CursorWidget(self.engine)
        self.widgets.append(cursor)
        '''
        #------------------------------------------------------------------



