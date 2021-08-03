from django.conf.urls import url, include
from sort import views
from django.urls import path


urlpatterns = [
    path('', views.sort),
    url(r'^api-auth/', include('rest_framework.urls', namespace='rest_framework'))
]