# _*_ coding: utf-8 _*_
 
from selenium import webdriver
import time
import json
from urllib.request import Request, urlopen
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
 
# 全局url
HOME_PAGE = 'https://www.xuexi.cn/'   # 学习强国官方url
LOGIN_LINK = 'https://pc.xuexi.cn/points/login.html'    # 登录url
SCORES_LINK = 'https://pc.xuexi.cn/points/my-points.html'   # 分数url
 
# 浏览器驱动
browser = webdriver.Chrome()
 
def login_simulation():
    """模拟登录"""  
    # 方式一：使用cookies方式
    # 先自己登录，然后复制token值覆盖
    # cookies = {'name': 'token', 'value': ''}
    # browser.add_cookie(cookies)
 
    # 方式二：自己扫码登录
    browser.get(LOGIN_LINK)    
    browser.execute_script("var q=document.documentElement.scrollTop=1000")
    time.sleep(10)
    browser.get(HOME_PAGE)
    print("模拟登录完毕\n")
 
def read_arts():
    """阅读文章"""
    print("阅读文章开始\n")
    # 通过分析，找到栏目url，拿到类似channelNames=学习时评这个栏目下的所有文章信息
    url = "https://www.xuexi.cn/lgdata/1ap1igfgdn2.json?_st=26593106"   # 获取文章Api    
    firefox_headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:78.0) Gecko/20100101 Firefox/78.0'}  # 包装头部    
    request = Request( url, headers=firefox_headers )   # 构建请求
    html = urlopen( request )   # 打开网页   
    data = html.read()  # 读取网页内容，是json数据    
    hjson = json.loads(data)  # json解析响应文本
    # print('响应解析后的类型：',type(hjson))     # 解析后是dict（字典）类型
    # print('响应解析后的键值对个数：',len(hjson))   # 字典键值对个数
    # 循环读取响应内容中“url”对应的值，设置“循环次数”=7
    for j in range(0,7,1):        
        articles= hjson[ j ]['url']        # 取url对应的值
        print(j)
        print(articles)
        time.sleep(5)
        browser.get(articles)
        #  滚动条
        for i in range(0, 2000, 100):
            js_code = "var q=document.documentElement.scrollTop=" + str(i)
            browser.execute_script(js_code)
            time.sleep(5)
        for i in range(2000, 0, -100):
            js_code = "var q=document.documentElement.scrollTop=" + str(i)
            browser.execute_script(js_code)
            time.sleep(5)
    print("阅读文章完毕\n")
 
 
def watch_videos():
    """观看视频"""
    print("播放视频开始\n")    
    url = 'https://www.xuexi.cn/lgdata/1novbsbi47k.json?_st=26597245'   # 获取视频Api
    firefox_headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:78.0) Gecko/20100101 Firefox/78.0'}
    request = Request( url, headers=firefox_headers )
    html = urlopen( request )    
    data = html.read()  # 获取数据    
    hjson = json.loads(data)    # json解析响应文本    
    spend_time = 0
    for j in range(0,6,1):
        videos= hjson[j]['url']        # 取url对应的值
        print(j)
        print(videos)
        time.sleep(2)
        browser.get(videos) # 打开浏览器
        time.sleep(5)
        element = browser.find_element(By.CSS_SELECTOR, "body")
        actions = ActionChains(browser)
        actions.move_to_element(element)
        actions.perform()        
        browser.find_element(By.CSS_SELECTOR, ".outter").click()    # 点击播放视频        
        # 获取视频时长
        video_duration_str = browser.find_element_by_xpath("//span[@class='duration']").get_attribute('innerText')
        video_duration = int(video_duration_str.split(':')[0]) * 60 + int(video_duration_str.split(':')[1])
        # 保持学习，直到视频结束
        time.sleep(video_duration + 3)
        spend_time += video_duration + 3
    print("播放视频完毕\n")
    
 
def get_scores():
    """获取当前积分""" 
    browser.get(SCORES_LINK)
    time.sleep(2)
    gross_score = browser.find_element_by_xpath("//*[@id='app']/div/div[2]/div/div[2]/div[2]/span[1]")\
                  .get_attribute('innerText')
    today_score = browser.find_element_by_xpath("//span[@class='my-points-points']").get_attribute('innerText')
    print("当前总积分：" + str(gross_score))
    print("今日积分：" + str(today_score))
    print("获取积分完毕，即将退出\n")
 
 
if __name__ == '__main__':
    login_simulation()  # 模拟登录
    get_scores()        # 获得今日积分
    read_arts()    
    watch_videos()     # 观看视频
    get_scores()        # 获得今日积分
    browser.quit()


