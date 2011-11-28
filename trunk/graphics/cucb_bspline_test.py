#!/usr/bin/python
#FileName: test.py

import wx
import cucb_gl as gl

class GFrame(wx.Frame):
	def __init__(self, parent, title):
		super(GFrame, self).__init__(parent, title=title, size=(400,300))

		wx.FutureCall(2000, self.Draw)

		self.Centre()
		self.Show()
	
	def Draw(self):

		size = 4;
		points = gl.points_create(size)
		pt1 = gl.DPoint()
		pt1.x = 0
		pt1.y = 100
		pt2 = gl.DPoint()
		pt2.x = 100
		pt2.y = 200
		pt3 = gl.DPoint()
		pt3.x = 200
		pt3.y = 200
		pt4 = gl.DPoint()
		pt4.x = 300
		pt4.y = 100

		gl.points_set_by_index(points, size, 0, pt1)
		gl.points_set_by_index(points, size, 1, pt2)
		gl.points_set_by_index(points, size, 2, pt3)
		gl.points_set_by_index(points, size, 3, pt4)
		#self.DrawPline(points, size)

		print 'spline:'
		spline_size = 9
		spline = gl.points_create(spline_size)

		#draw begin
		gl.cubic_b_spline_interp(pt1, pt1, pt1, pt2, spline, spline_size)
		self.DrawPline(spline, spline_size)
		gl.cubic_b_spline_interp(pt1, pt1, pt2, pt3, spline, spline_size)
		self.DrawPline(spline, spline_size)

		#draw spline
		gl.cubic_b_spline_interp(pt1, pt2, pt3, pt4, spline, spline_size)
		self.DrawPline(spline, spline_size)

		#draw end
		gl.cubic_b_spline_interp(pt2, pt3, pt4, pt4, spline, spline_size)
		self.DrawPline(spline, spline_size)
		gl.cubic_b_spline_interp(pt3, pt4, pt4, pt4, spline, spline_size)
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
	GFrame(None, 'B-spline test')
	app.MainLoop()
