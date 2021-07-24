import sys;
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton;
from PyQt5.QtCore import QCoreApplication;
from PyQt5.QtGui import QIcon;

class MyApp(QWidget) :

	def __init__(self) :
		super().__init__();
		self.initUI();

	def initUI(self) :
		btn = QPushButton('Quit',self);
		btn.move(50,50);
		btn.resize(btn.sizeHint());	
		btn.clicked.connect(QCoreApplication.instance().quit);

		self.showWindowTitle('Quit Button');

if __name__ == '__main__' :
	app = QApplication(sys.argv);
	ex = MyApp();
	sys.exit(app.exec_());