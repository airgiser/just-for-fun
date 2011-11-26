#!/usr/bin/python
#FileName: test.py

import wx
import cucb_gl as gl

class GFrame(wx.Frame):
	def __init__(self, parent, title):
		super(GFrame, self).__init__(parent, title=title, size=(400,300))

		wx.FutureCall(2000, self.DrawLine)

		self.Centre()
		self.Show()
	
	def DrawLine(self):

		size = 3
		points = gl.points_create(size)
	
		pt = gl.DPoint()
		pt.x = 100
		pt.y = 100
		gl.points_set_by_index(points, size, 0, pt)
		pt.x = 100
		pt.y = 200
		gl.points_set_by_index(points, size, 1, pt)
		pt.x = 200
		pt.y = 200
		gl.points_set_by_index(points, size, 2, pt)

		spline_size = 9
		spline = gl.points_create(spline_size)
		gl.bezier_spline(points, size, spline, spline_size) 

		self.DrawPline(points, size)
		print 'spline:'
		self.DrawPline(spline, spline_size)

	def DrawPline(self, points, size):

		dc = wx.ClientDC(self)

		spt = gl.DPoint()
		ept = gl.DPoint()
		for i in range(0, size):
			gl.points_get_by_index(points, size, i, spt)
			print spt.x
			print spt.y
			if i+1 < size:
				gl.points_get_by_index(points, size, i+1, ept)
				dc.DrawLine(spt.x, spt.y, ept.x, ept.y)


if __name__ == '__main__':

	app = wx.App()
	GFrame(None, 'Bezier spline test')
	app.MainLoop()
