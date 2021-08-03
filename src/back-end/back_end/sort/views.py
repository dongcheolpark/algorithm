from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt
import subprocess

@csrf_exempt
def sort(request):
    size = str(request.GET['size'])
    sort_type = str(request.GET['type'])
    print(size, sort_type)
    subprocess.run(['./program', size, sort_type])
    result = open('out.json')
    return HttpResponse(result)