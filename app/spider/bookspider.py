#!/usr/bin/python
# FileName: bookspider.py

import os
import sys
import time
import re
import urllib
import urllib2

from urllib import urlopen

#root_url = "http://book.xxx.com/subject/"
#page_id = 1230413
#root_url = "http://movie.xxx.com/subject/"
#page_id = 1292001

root_url = ""
pages = []

def is_page_existed(pageid):
    for ipage in pages:
        if ipage == pageid:
            return True
    return False

def request_content(url):
    try:
        req = urllib2.Request(url)
        req.add_header("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36")
        request = urllib2.urlopen(req)
    except urllib2.URLError, e:
        return ""
    except urllib2.HttpError, e:
        return ""
    content = request.read()
    return content

def get_title(content):
    find = re.search(r'<title>(.*?)</title>', content)
    if (find == None):
        find = re.search(r'<title>\n(.*?)\n</title>', content)
    if (find == None):
        return ""
    title = find.group(1).strip().decode('utf-8')
    return title;

def get_score(content):
    find = re.search(r'<strong class=.*? property=.*?>.*?(\d\.\d)', content)
    if (find == None):
        return ""
    score = find.group(1)
    return score

def add_link_pages(content):
    find = re.findall(root_url + r'(\d{7,8})', content)

    for pageid in find:
        if not is_page_existed(pageid):
            pages.append(pageid)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print "bookspider.py root_url page_id"
        sys.exit()

    root_url = sys.argv[1]
    page_id = sys.argv[2]
    pages.append(str(page_id))

    cursor = 0
    while cursor < len(pages):
        # URL string
        url = root_url + pages[cursor]
        cursor += 1

        # http request
        content = request_content(url)
        if len(content) == 0:
            continue

        # title 
        title = get_title(content)

        # score
        score = get_score(content)

        # print
        if float(score) >= 9.0:
            print ('title:%s score:%s url:%s') % (title, score, url)

            # sleep
            time.sleep(2)

        # links
        add_link_pages(content)
        time.sleep(0.1)

